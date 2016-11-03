#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
using namespace std;

int minDistance(string s1, string s2) {
	int n1 = s1.size();
	int n2 = s2.size();
	
	// dp[i][j]��ʾs1��ǰi���ַ����ɵ��Ӵ���s2��ǰj���ַ�
	// ���ɵ��Ӵ��ı༭����
	vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
	
	// �����һ���ַ����ǿմ����������������ڶ��ִ�,��˱༭����
	// �ǵڶ��ַ����ĳ��ȣ���֮����ڶ����ַ����ǿմ������һ���ַ���
    // ����ɾ�����е��ַ����ܱ�ɵڶ����ַ���
	for (int j = 0; j <= n2; ++j) {
		dp[0][j] = j;
	}
	for (int i = 0; i <= n1; ++i) {
		dp[i][0] = i;
	}
	dp[0][0] = 0;
	
	// ��s1��s2���²���һ���ַ�c1, c2�󣬸�������뷽ʽ�����������
	// 1. c1��c2���룬��ʱ���c1==c2��༭����Ϊdp[i-1][j-1], ����
	//    ��Ҫ�滻c1Ϊc2������+1, replce_cost
	// 2. c1��s2��ǰj-1�ַ�����, ���ʱ��Ҫ��s1�ֲ���һ���µ�c2, insert_cost
	// 3. c2��s1��ǰi-1�ַ����룬��ʱ��Ҫɾ��s1�²����c1�ַ�, delete_cost
	for (int i = 1; i <= n1; ++i) {
		for (int j = 1; j <= n2; ++j) {
			int replace_cost = dp[i-1][j-1] + (s1[i-1]==s2[j-1]?0:1);
			int insert_cost = dp[i][j-1] + 1;
			int delete_cost = dp[i-1][j] + 1;
			dp[i][j] = min(replace_cost, min(insert_cost, delete_cost));
		}
	}
	return dp[n1][n2];
}

int main()
{
	string w1 = "appe";
	string w2 = "apple";
	cout << minDistance(w1, w2) << endl;
	return 0;
}
