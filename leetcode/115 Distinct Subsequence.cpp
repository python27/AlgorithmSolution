#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

/*
 * �ݹ�ⷨ�������������ص�������
 */
int numDistinct(string s, string p) {
    if (p.size() > s.size()) return 0;
    if (p.size() == s.size()) return p == s?1:0;

    int pn = p.size();
    int sn = s.size();

    char last_ch = p[pn-1];
    int cnt  = 0;
    for (int j = sn-1; j >= max(0, pn-1); --j) {
        if (last_ch == s[j]) {
            cnt += numDistinct(s.substr(0, j), p.substr(0, pn-1));
        }
    }
    return cnt;
}

/*
 * ��̬�滮
 * dp[i][j] = p��ǰi���ַ���s��ǰj���ַ��ľ��еĲ�ͬ��������Ŀ
 * dp[i][j] = \sum_k {dp[i][k]}; k <= j && s[k-1] == p[i-1]
 */

int numDistinct2(string s, string p) {
	int pn = p.size();
	int sn = s.size();
	vector<vector<int>> dp(pn+1, vector<int>(sn+1, 0));
	for (int j = 0; j <= sn; ++j) dp[0][j] = 1;
	for (int i = 1; i <= pn; ++i) dp[i][0] = 0;

	for (int i = 1; i <= pn; ++i) {
		for (int j = i; j <= sn; ++j) {
			dp[i][j] = 0;
			char ch = p[i-1];
			for (int k = i-1; k <= j-1; ++k) {
				if (s[k] == ch) {
					dp[i][j] += dp[i-1][k];
				}
			}
		}
	}
	return dp[pn][sn];
}

/*
 * ������ʱ�临�Ӷ���Ȼ���ߣ����ڽ�һ���Ż��Ŀռ�
 * ������һ���ַ�����ȣ���ô������dp[i][j-1]��ֵ
 * �������һ���ַ���ȣ��������������
 *    ���һ�����һ���ַ����,����Ҫ��dp[i-1][j-1]��ֵ
 *    �����: û�������һ���ַ���ԣ�����Ҫ��dp[i][j-1]��ֵ
 */
int numDistinct3(string s, string p) {
	int pn = p.size();
	int sn = s.size();
	vector<vector<int>> dp(pn+1, vector<int>(sn+1, 0));
	for (int j = 0; j <= sn; ++j) dp[0][j] = 1;
	for (int i = 1; i <= pn; ++i) dp[i][0] = 0;

	for (int i = 1; i <= pn; ++i) {
		for (int j = i; j <= sn; ++j) {
			if (p[i-1] != s[j-1]) {
				dp[i][j] = dp[i][j-1];
			} else {
				dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
			}
		}
	}
	return dp[pn][sn];
}

int main()
{
	string s = "rabbbit";
	string p = "rabbit";
	cout << numDistinct2(s, p) << endl;
	return 0;
}

