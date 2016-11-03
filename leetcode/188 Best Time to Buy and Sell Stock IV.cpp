#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
using namespace std;

int maxProfitNoLimit(vector<int>& prices) {
	int n = prices.size();
	if (n <= 1) return 0;
	int ans = 0;
	for (int j = 1; j < n; ++j) {
		if (prices[j] > prices[j-1]) {
			ans += prices[j] - prices[j-1];
		}
	}
	return ans;
}

int maxProfit(int k, vector<int>& prices) {
	int n = prices.size();
	// dp[t][j]��ʾ�Գ���Ϊj�������ò�����t�εĽ���
	// �ܻ�ȡ�������������������dp[2][n]
	if (n <= 1) return 0;
	
	// �Ż�ʱ�临�Ӷ�
	if (k >= n / 2) return maxProfitNoLimit(prices);

	vector<vector<int>> dp(k+1, vector<int>(n+1, 0));
	// 0 �ν��ײ��ܻ���κ�����
	for (int j = 0; j <= n; ++j) dp[0][j] = 0;
	// ����Ϊ0�����鲻�ܻ���κ�����
	for (int i = 0; i <= k; ++i) dp[i][0] = 0;

	// ���һ��Ԫ��prices[j]������ѡ��
	// 1. ���һ�ν��װ���prices[j]
	// 2. t�ν��׾�������prices[j],��dp[t][j] = dp[t][j-1]
	// dp[t][j] = max(dp[t][j-1], max(prices[j-1]-prices[jj-1]+dp[t-1][jj-1])
	//          = max(dp[t][j-1], prices[j-1]+max(dp[t-1][jj-1]-prices[jj-1]))
	// jj in [1, j)
	for (int t = 1; t <= k; ++t) {
		dp[t][1] = 0; // 1��Ԫ��t�ν�������Ϊ0
		int prev_temp_max = dp[t-1][0] - prices[0];
		for (int j = 2; j <= n; ++j) {
			dp[t][j] = max(dp[t][j-1], prices[j-1]+prev_temp_max);
			prev_temp_max = max(prev_temp_max, dp[t-1][j-1]-prices[j-1]);
		}
	}
	return dp[k][n];
}
