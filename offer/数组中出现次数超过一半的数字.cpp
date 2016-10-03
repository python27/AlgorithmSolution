#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Ѱ�ҳ��ִ�������һ���Ԫ��
 * 1. ���õ�ǰԪ��ΪѰ��Ԫ�أ�����flag=1
 * 2. ����ÿһ��Ԫ�أ�������뵱ǰԪ����ȣ���flag++; ������flag--
 * 3. �κ�ʱ��flag = 0�������õ�ǰԪ��Ϊ��ѡԪ�أ�flag = 1
 * 4. ��֤������Ԫ���Ƿ�����ǳ��ֹ���
 */
int MoreThanHalfNum_Solution(vector<int> numbers) {
	if (numbers.empty()) return 0;
	
	int n = static_cast<int>(numbers.size());
	int flag = 1;
	int cur = numbers[0];
	for (int i = 1; i < n; ++i) {
		if (flag == 0) {
			flag = 1;
			cur = numbers[i];
		} else {
			if (numbers[i] == cur) flag += 1;
			else flag -= 1;
		}
	}
	
	if (flag == 0) {
		return 0;
	} else {
	    // verify whether the number is truly more than half
	    int cnt = 0;
	    for (int i = 0; i < n; ++i) {
		    if (numbers[i] == cur) cnt++;
	    }
	    
	    if (cnt * 2 > n) return cur;
	    else return 0;

	}
}

int main()
{
	vector<int> v = {1,2,3,2,4,2,5,2,3};
	//cout << "v.size():" << v.size() << endl;
	cout << MoreThanHalfNum_Solution(v) << endl;
	return 0;
}
