#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
using namespace std;

typedef long long llong;
const llong MOD = 12357;

vector<vector<llong>> MatrixMultiply(const vector<vector<llong>>& A, const vector<vector<llong>>& B)
{
	int rowa = A.size();
	int cola = A[0].size();
	int rowb = B.size();
	int colb = B[0].size();

	vector<vector<llong>> ans(rowa, vector<llong>(colb, 0));
	assert(cola == rowb);
	for (int i = 0; i < rowa; ++i)
	{
		for (int j = 0; j < colb; ++j)
		{
			ans[i][j] = 0;
			for (int k = 0; k < cola; ++k)
			{
				ans[i][j] += A[i][k] * B[k][j];
			}
			// avoid the result overflow
			ans[i][j] %= MOD;
		}
	}
	return ans;
}


vector<vector<llong>> MatrixPower(const vector<vector<llong>>& A, llong m)
{
	int n = A.size();
	vector<vector<llong>> ans(n, vector<llong>(n, 0));
	for (int i = 0; i < n; ++i) ans[i][i] = 1;

	if (m == 0) 
	{
		return ans;
	}
	else if (m % 2 == 0)
	{
		return MatrixPower(MatrixMultiply(A, A), m / 2);
	}
	else
	{
		return MatrixMultiply(A, MatrixPower(A, m - 1));
	}
}

int main()
{
	freopen("data.in", "r", stdin);
	llong N = 0;
	cin >> N;

	vector<vector<llong>> matrix(8, vector<llong>(8, 0));
	for (int i = 0; i < 8; ++i) matrix[i][7-i] = 1;
	matrix[3][7] = 1;
	matrix[6][7] = 1;
	matrix[7][3] = 1;
	matrix[7][6] = 1;

	vector<llong> init(8, 0);
	init[7] = 1;

	vector<vector<llong>> ans = MatrixPower(matrix, N);
	cout << ans[7][7] % MOD << endl;

	return 0;
}