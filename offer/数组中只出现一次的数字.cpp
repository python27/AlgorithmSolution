#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * �򵥰汾��
 * ����ֻ���ֽ���һ�����ֳ���һ�Σ����������־��������ε����⣬����ͨ��
 * ����������ֱ�����õ����
 *
 * ���Ӱ汾��
 * ����ͨ����ԭ����ָ�Ϊ���������飬ʹ��ÿ���������иպð�������һ�����֣�
 * ���������ת��Ϊ�򵥰汾������
 * 1. ����ͨ�����������������Եõ� num1 ^ num2
 * 2. �����������ֲ���ȣ����Ա�Ȼ����ĳ��bitλ���ڸ�λ��һ��Ϊ1һ��Ϊ0
 * 3. �ҵ�������bitλ�󣬽����и�λ��Ϊ1�����ֹ�Ϊһ�飻Ϊ0�Ĺ�Ϊ��һ�飻
 *    ����ת��Ϊ�򵥰汾������
 */
void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
	int n = static_cast<int>(data.size());

	int xor_result = 0;
	for (int i = 0; i < n; ++i) {
		xor_result = xor_result ^ data[i];
	}

	*num1 = 0;
	*num2 = 0;
	int low_bit_mask = xor_result & (-xor_result);
	for (int i = 0; i < n; ++i) {
		if (data[i] & low_bit_mask) {
			*num1 ^= data[i];
		} else {
			*num2 ^= data[i];
		}
	}
	return;
}

int main()
{
	vector<int> v = {5, 3, 2, 1, 2, 5};
	int n1 = 0; int n2 = 0;
	FindNumsAppearOnce(v, &n1, &n2);
	cout << n1 << endl;
	cout << n2 << endl;
	return 0;
}
