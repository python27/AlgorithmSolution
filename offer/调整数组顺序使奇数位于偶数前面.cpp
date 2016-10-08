#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

/*
 * �ռ任ʱ�䣬��O(n)��ʱ�����Ƚ����е�����ȡ��
 * Ȼ������ż��ȡ��������
 * O(n) ʱ�� O(n) �ռ�
 */

void reOrderArray(vector<int> &array) {
	int n = static_cast<int>(array.size());
	vector<int> ans;
	for (int i = 0; i < array.size(); ++i) {
		if (array[i] % 2 == 1) ans.push_back(array[i]);
	}
	
	for (int i = 0; i < array.size(); ++i) {
		if (array[i] % 2 == 0) ans.push_back(array[i]);
	}
	array = ans;
	return;
}
