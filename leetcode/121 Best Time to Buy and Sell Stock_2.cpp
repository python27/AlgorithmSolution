#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
using namespace std;

int maxProfit(vector<int>& price) {
	int n = price.size();
	if (n <= 1) return 0;
	
	int ans = 0;
	// ��¼��ǰ��������СԪ��
	int sofar_min = price[0];
	for (int j = 1; j < n; ++j) {
		// ����ÿ����Ʊ�۸���������СԪ�ش�
        // ��ʱ������������Բ�������, ���½��
		if (price[j] >= sofar_min) {
			ans = max(ans, price[j] - sofar_min);
		}
		// ����Ŀǰ��������СԪ��
		sofar_min = min(sofar_min, price[j]);
	}
	return ans;
}

int main()
{
	//int a[] = {7, 1, 5, 3, 6, 4};
	int a[] = {7, 6, 4, 3, 1};
	int n = sizeof(a) / sizeof(a[0]);
	vector<int> v(a, a+n);
	cout << maxProfit(v) << endl;
	return 0;
}
