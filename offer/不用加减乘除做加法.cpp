#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * ʹ��λ�������ӷ�
 * �� [���] ����������²���λ�Ľ��
 * �� [��] Ԫ�������½�λ�Ľ��������������
 *
 */
int Add(int num1, int num2)
{

	int sum = num1 ^ num2;
	int carry = num1 & num2;
	if (carry == 0) {
		return sum;
	} else {
		return Add(sum, (carry<<1));
	}

}

int main()
{
	cout << Add(1, 2) << endl;
	cout << Add(8, 13) << endl;
	cout << Add(-21, -36) << endl;
	cout << Add(21, -15) << endl;
	return 0;
}
