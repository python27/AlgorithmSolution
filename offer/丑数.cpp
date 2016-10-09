#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * ���� bottom to up
 * 1. �ؼ���������һ��������β�������һ�������϶����ɱȵ�ǰ����С��ĳ����
 *    ����2������3������5�õ����������е���С��
 * 2. ������Ҫ���ϵ�׷���������ȵ�ǰ����С�������Ǹ������������������
 *    ��������ʾ��Ϊ��ʹ����󻯣�ÿ�����º���Ҫ���ϵĽ���������������ֱ��
 *    �����ٳ���һ��2,3,5���Ҳ����ڵ�ǰ����Ϊֹ
 */

int GetUglyNumber_Solution(int index) {
	if (index <= 0) return 0;
	if (index == 1) return 1;
	vector<int> v(index, 0);
	v[0] = 1;
	int idx2 = 0;
	int idx3 = 0;
	int idx5 = 0;
	int cur_index = 0;
	while (cur_index < index-1) {
		int nextUgly = min(min(v[idx2]*2, v[idx3]*3), v[idx5]*5);
		v[cur_index+1] = nextUgly;
		
		while (idx2 < index && v[idx2] * 2 <= nextUgly) idx2++;
		while (idx3 < index && v[idx3] * 3 <= nextUgly) idx3++;
		while (idx5 < index && v[idx5] * 5 <= nextUgly) idx5++;
		cur_index++;
	}
	
	return v[index-1];
}

int main()
{
	cout << GetUglyNumber_Solution(30) << endl;
	return 0;
}
