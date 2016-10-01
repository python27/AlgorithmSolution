#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 쳲��������б���
 *
 * ���ݵ�һ��С���η��õķ�ʽ�����Խ�������Ϊ
 * f(n-1)�������f(n-2)�����, �����У�
 * f(n) = f(n-1) + f(n-2)
 */
int rectCover(int number) {
	if (number <= 0) return 0;
	int f1 = 1;
	int f2 = 2;
	int i = 1;
	while (i < number) {
		int f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
		i++;
	}
	return f1;
}

int main()
{
	cout << rectCover(1) << endl;
	cout << rectCover(2) << endl;
	cout << rectCover(3) << endl;
	cout << rectCover(4) << endl;
	return 0;

}
