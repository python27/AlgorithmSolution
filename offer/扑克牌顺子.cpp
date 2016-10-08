#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cassert>
using namespace std;

/*
 * �˿���˳���ж�
 * 1. �����������򣬼��������˿��ƵĿ�ȱ���������ȱ��С�ڵ���
 *    ��ĸ�������˵��������ֲ���ȱ���γ�˳�ӣ������С�
 * 2. ע��������ֶ��ӣ����Ȼ��������˳�ӣ�ֱ�ӷ���
 */
bool IsContinuous(vector<int> numbers) {
    if (numbers.empty()) return false;

	int n = static_cast<int>(numbers.size());
	sort(numbers.begin(), numbers.end());
	int i = 0;
	while (i < n && numbers[i] == 0) i++;
	int n_zero = i;

	//assert(i < n);
	int gap = 0;
	for (int j = i; j < n; ++j) {
		if (j + 1 < n) {
			// equal pairs, cannot be continuous
			if (numbers[j+1] - numbers[j] == 0) {
				return false;
			} else { // count the gaps between two numbers
				gap += numbers[j+1]-numbers[j]-1;
			}
		}
	}

	return gap <= n_zero;
}
