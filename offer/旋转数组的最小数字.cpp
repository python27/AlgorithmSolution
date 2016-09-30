#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/**
 * ���ֲ��ұ�����Ŀ��
 * ʵ���Ͼ��Ǹ����м�Ԫ����˵�Ԫ�صıȽ����ж�
 * ��Сֵλ���Ǹ����䣺�����������ұ�����
 * ע����ֲ����ǣ�ÿ�ε������뱣֤����������С�ģ�
 * ��Ȼ�������ѭ��
 *
 * 1 2 3 4 5 6 7
 * case 1: 3 4 5 6 7 1 2
 * case 2: 6 7 1 2 3 4 5
 */
int minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.empty()) return 0;
    int n = static_cast<int>(rotateArray.size());
    int i = 0;
    int j = n - 1;
    while (i < j) {
        int mid = i + (j-i)/2;
        if (rotateArray[mid] <= rotateArray[j]) {
            j = mid;
        } else {
            i = mid + 1;
        }
    }
    return rotateArray[i];
}

int main()
{
    //int a[7] = {1, 2, 3, 4, 5, 6, 7};
    //int a[7] = {3, 4, 5, 6, 7, 1, 2};
    int a[7] = {5, 6, 7, 1, 2, 3, 4};
    vector<int> v(a, a+7);
    cout << minNumberInRotateArray(v) << endl;
    return 0;
}
