#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * ���ַ���������
 * Excellent Solution
 *
 * �����ⷨ��
 * Ҳ���Զ����������ֲ��Һ����ֱ���ҵ�һ��k�����һ��k
 * Ȼ������м�Ĳ�ֵ����
 */
int GetCountOfKRecursion(vector<int> A, int lo, int hi, int k) {
	if (lo > hi) return 0;
	if (lo == hi) {
		if (A[lo] == k) return 1;
		else return 0;
	}
	
	int mid = lo + (hi - lo) / 2;
	if (A[mid] < k) {
		return GetCountOfKRecursion(A, mid+1, hi, k);
	} else if (A[mid] > k) {
		return GetCountOfKRecursion(A, lo, mid-1, k);
	} else if (A[mid] == k) {
		int cnt1 = GetCountOfKRecursion(A, lo, mid-1, k);
		int cnt2 = GetCountOfKRecursion(A, mid+1, hi, k);
		return cnt1+cnt2+1;
	}
	return 0; // otherwise stupid compiler will give a WARN
}

int GetNumberOfK(vector<int> data ,int k) {
	int n = static_cast<int>(data.size());
	return GetCountOfKRecursion(data, 0, n-1, k);
}
