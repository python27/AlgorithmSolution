#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

int lengthOfLongestSubstring(string s) {
	int n = static_cast<int>(s.size());
	int ans = 0;
	int hash[256];
	memset(hash, -1, sizeof(hash));
	
	int i = 0;
	int j = 0;
	while (j < n) {
		int ch = s[j];
		// ���û�г��ֹ�����ֱ������ƶ�
		if (hash[ch] == -1) {
			hash[ch] = j;
			ans = max(ans, j-i+1);
			j++;
		} else {
		// ������ֹ����������һ�γ��ֵ�λ��,�������Ӵ���ʼλ��i
			i = max(i, hash[ch]+1);
			hash[ch] = j;
			ans = max(ans, j-i+1);
			j++;
		}
	}
	return ans;
}

int main()
{
	string s = "abcabcbb";
	string s2 = "aab";
	cout << lengthOfLongestSubstring(s2) << endl;
	return 0;
}
