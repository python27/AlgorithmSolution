#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * ��ѯ����Ԫ��
 */
bool duplicate(int numbers[], int length, int* duplication) {
	if (numbers == NULL) return false; // invalid input
	if (length <= 0) return false; // invalid input
	if (length == 1) return false; // cannot have duplicates
	
	for (int i = 0; i < length; ++i) {
		if (numbers[i] != i) {
			int num = numbers[i]; // ��ǰλ�õ�Ԫ������
			numbers[i] = -1;      // �õ�ǰλ��Ϊ��
			if (num == numbers[num]) { // ���Ŀ��λ������Ԫ������ȡ������ظ�
				*duplication = num;
				return true;
			} else {
				// ���Ŀ��λ�ò��գ���Ԫ�ز����ڵ�ǰԪ�أ������
		        while (numbers[num] != -1 && num != numbers[num]) {
		            int temp = numbers[num];
                    numbers[num] = num;
                    num = temp;
				}
				if (numbers[num] == -1) { // ���Ŀ��λ��Ϊ�գ���ֱ�ӷ���
					numbers[num] = num;
				} else if (numbers[num] == num) { // ��֮��Ŀ��λ�ò�������ȣ������ظ�
					*duplication = num;
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	int a[] = {2, 1, 3, 1, 4};
	int n = 5;
	int dup = -1;
	cout << duplicate(a, n, &dup) << endl;
	cout << dup << endl;
	return 0;
}
