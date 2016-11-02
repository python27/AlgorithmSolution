#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cstdio>
using namespace std;

/*
 * �����Ե�ǰbarΪ��̱ߵľ��ε�������������������bar��
 * ��ô���ǾͿ��Եõ�������������ֵ
 *
 * ���������Ҫ֪����߱ȵ�ǰbarС��bar��λ�ú��ұ߱ȵ�ǰbar
 * С�ĵ�һ��bar��λ�ã����֪��������λ���أ������ǰԪ�ر�ջ��
 * Ԫ�ش���push������pop��ջ��Ԫ��tp�����Ҽ�����tpΪ���bar�����
 * ��ô��tpΪ���bar�����Ҹ��������ֱ��ǵ�ǰ����i��ջ�ڵ�ǰһ������
 */
int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();
	stack<int> S;
	
	int max_area = 0;
	int i = 0;
	while (i < n) {
		if (S.empty() || heights[i] >= heights[S.top()]) {
			S.push(i);
			i++;
		} else {
			int tp = S.top(); S.pop();
			int left_idx = S.empty() ? -1 : S.top();
			int local_area = (i-left_idx-1) * heights[tp];
			max_area = max(max_area, local_area);
		}
	}
	
	while (!S.empty()) {
		int tp = S.top(); S.pop();
		int left_idx = S.empty() ? -1 : S.top();
		int local_area = (i-left_idx-1) * heights[tp];
		max_area = max(max_area, local_area);
	}
	
	return max_area;
}

int main()
{
	int a[] = {2,1,5,6,2,3};
	//int a[] = {6, 2, 5, 4, 5, 1, 6};
	int n = sizeof(a) / sizeof(a[0]);
	
	vector<int> v(a, a+n);
	cout << "vector" << endl;
	for (size_t i = 0; i < v.size(); ++i) cout << " " << v[i];
	cout << endl;
	cout << largestRectangleArea(v) << endl;
	return 0;
}
