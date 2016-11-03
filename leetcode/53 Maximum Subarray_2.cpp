#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
using namespace std;

int maxSubArray(vector<int>& A) {
	int n = A.size();
	if (n == 0) return 0;
	if (n == 1) return A[0];
	
	// dp[i] ��ʾ��i��β���������������ĺ�
	vector<int> dp(n, 0);
	dp[0] = A[0];
	int ans = dp[0];
	// ���ڶ�i��Ԫ�أ�ֻ�����ֿ�����i-1��β������
	// �����µ������飬�����Լ���������������
	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i-1]+A[i], A[i]);
		ans = max(ans, dp[i]);
	}

	return ans;
}

int main()
{
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	int n = sizeof(a)/sizeof(a[0]);
	vector<int> v(a, a+n);
	cout << maxSubArray(v) << endl;
	return 0;
}
