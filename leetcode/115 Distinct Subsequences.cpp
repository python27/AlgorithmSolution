#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
using namespace std;

int numDistinct(string S, string T) {
	int n1 = T.size();
	int n2 = S.size();
	
	// dp[i][j]��ʾT��ǰi���ַ����ɵ��ַ�������S��
	// ��ǰj���ַ����ɵ��ַ�������Ϊ�����г��ֵĴ���
	// ������ǵ�Ŀ������� dp[n1][n2]
	vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
	
	// TΪ�մ�ʱ����S�г��ֵĴ���Ϊ1�Σ���Ϊû�б��ɾ��
	// ������ֻ�ܽ�S�е������ַ���ɾ��
	for (int j = 0; j <= n2; ++j) {
		dp[0][j] = 1;
	}
	
	// SΪ�մ�ʱ������T���κηǿ��Ӵ����������ܰ�����������
	for (int i = 1; i <= n1; ++i) {
		dp[i][0] = 0;
	}
	
	// ����T�ĵ�i���ַ���S�ĵ�j���ַ������T[i]==S[j],��ô�����ֿ���:
	// 1. T[i]��S[j]���룬�������и���Ϊ֮ǰ��ֵ, �� dp[i-1][j-1]
	// 2. �������߲��ܶ���, T[i]������S��ǰj-1���ַ�����, ��Ϊ dp[i][j-1]
	// �����T[i]!=S[j],��ôT[i]��S[j]���ܶ��룬ֻ����������2�����
	for (int i = 1; i <= n1; ++i) {
		for (int j = 1; j <= n2; ++j) {
			if (T[i-1] == S[j-1]) {
				dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
			} else {
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	
	return dp[n1][n2];
}

int main()
{
	string T = "rabbit";
	string S = "rabbbit";
	cout << numDistinct(S, T) << endl;
	return 0;
}
