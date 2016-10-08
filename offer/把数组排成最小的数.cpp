#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cassert>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*
 * ����Ŀ��һ���ǳ�����˼����
 * 1. ʵ���Ͼ������һ�����У�ʹ��������е�ֵ��С�����仰˵������ϣ�����������
 *    ���򣬰��������������õ���ֵ��С
 * 2. ��Ϊ��sort�����Ĵ��ڣ�����ֻ��Ҫ������������Ԫ�صĴ�С�жϼ��ɣ���ô���
 *    �ķ������ǱȽ�ab���к�ba���У�ȡ��С�ļ���
 *
 * �ؼ���Ҫ��Ҫ���һ����������
 */
bool cmp(int a, int b) {
	char temp_a[64] = {'\0'};
	char temp_b[64] = {'\0'};
	sprintf(temp_a, "%d", a);
	sprintf(temp_b, "%d", b);
	string str_a(temp_a);
	string str_b(temp_b);
	return str_a+str_b < str_b+str_a;
}

string PrintMinNumber(vector<int> numbers) {
	sort(numbers.begin(), numbers.end(), cmp);
	string ans="";
	for (size_t i = 0; i < numbers.size(); ++i) {
		char temp[64] = {'\0'};
		sprintf(temp, "%d", numbers[i]);
		ans += string(temp);
	}
	return ans;
}

int main()
{
	vector<int> v = {3, 32, 321};
	cout << PrintMinNumber(v) << endl;
	return 0;
}
