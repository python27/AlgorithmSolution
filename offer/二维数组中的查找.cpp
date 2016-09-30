#include <iostream>
#include <vector>
using namespace std;

/**
 * �����ڶ���������ֻ�����Ƕ�ά��������
 * �����½ǻ������Ͻ�Ԫ����Ϊ�Ƚϵ�midԪ�أ�
 * ���ݶ��壺�������Ԫ�ر�Ȼ����С��
 *           �������Ԫ�ر�Ȼ������
 * ��ˣ����target����midԪ�أ�������ų��������Ԫ�أ���������
 *       ���targetС��midԪ�أ�������ų��������Ԫ�أ���������
 * ����ÿ�αȽϿ����ų�һ�л���һ�У�����ܵĸ��Ӷ�ΪO(m+n)
 */
bool Find(vector<vector<int> > A,int target)
{
	if (A.empty()) return false;

	int m = static_cast<int>(A.size());
	int n = static_cast<int>(A[0].size());

	int i = m - 1;
	int j = 0;
	while (i >= 0 && j < n) {
		if (A[i][j] == target) {
			return true;
		} else if (A[i][j] < target) {
		    j++;
        } else {
            i--;
        }
	}
	return false;
}
