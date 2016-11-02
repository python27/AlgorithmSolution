#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

//Ӣ������˵������
int trap(vector<int>& height) {
	if (height.empty()) return 0;
	
	int l = 0;
	int r = height.size() - 1;
	// ��ߵ������ұߵ�������trap�κ�water
	while (l < r && height[l] < height[l+1]) l++;
	while (l < r && height[r] < height[r-1]) r--;
	int sum = 0;
	
	while (l < r) {
		// ��߽���ͣ����Ըñ߽��ܹ�trap����water
		if (height[l] <= height[r]) {
			int j = l+1;
			while (j < r && height[j] < height[l]) {
				sum += height[l] - height[j];
				j++;
			}
			l = j;
		// �ұ߽���ͣ������ұ߽�Ϊ������trap����water
		} else {
			int j = r-1;
			while (j > l && height[j] < height[r]) {
				sum += height[r] - height[j];
				j--;
			}
			r = j;
		}
	}
	return sum;
}

// ʹ��ջ, ����ֱ��ͼ��������
int trap(vector<int>& height) {
	int n = height.size();
	stack<int> S;
	int ans = 0;
	
	int i = 0;
	while (i < n) {
		//printf("\n\nIteration %d\n", i);
		if (S.empty() || height[i] <= height[S.top()]) {
			S.push(i);
			//printf("Push to Stack: height[%d] = %d\n", i, height[i]);
			i++;
		} else {
			int tp = S.top(); S.pop();
			//printf("Pop: height[%d] = %d\n", tp, height[tp]);
			int left_idx = S.empty() ? -1 : S.top();
			//printf("compute the water between [%d, %d]\n", left_idx, i);
			if (left_idx != -1) {
				int temp = (min(height[i], height[left_idx])-height[tp])*(i-left_idx-1);
				//cout << "temp="<< temp << endl;
                ans += temp;
			}
		}
	}
	
	return ans;
}


int main()
{
	//int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int a[] = {2, 0, 2};
	int n = sizeof(a) / sizeof(a[0]);
	vector<int> v(a, a+n);
	cout << trap2(v) << endl;
	return 0;
}
