#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/**
 * �⺯��ʵ������
 *
 * 1. �����ݺ�����ʱ��Ҫ����ָ�����������Ǹ���
 * 2. ע�����Ϊ0�����
 */
double Power(double base, int exponent) {
	const double EPS = 1E-8;
	double ans = 1.0;
	if (exponent == 0) {
		return 1.0;
	} else if (exponent > 0) {
		while (exponent != 0) {
			if (exponent % 2 == 1) ans *= base;
			base *= base;
			exponent /= 2;
		}
		return ans;
	} else {
		exponent = -exponent;
		while (exponent != 0) {
			if (exponent % 2 == 1) ans *= base;
			base *= base;
			exponent /= 2;
		}
		if (ans == 0.0) {
			return 0.0;
		} else {
			return 1.0/ans;
		}
	}
}

int main() {
	cout << Power(-2.0, 3) << endl;
	cout << Power(-2.0, -3) << endl;
	cout << Power(-2.0, 0) << endl;
	return 0;
}
