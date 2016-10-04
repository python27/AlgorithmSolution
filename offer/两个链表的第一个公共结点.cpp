#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * ��������������
 * 1. ������������ĳ���n1, n2
 * 2. ��������������|n1-n2|���ڵ�
 * 3. ͬ������ֱ����������, ���򲻴���
 */
ListNode* FindFirstCommonNode(ListNode *head1, ListNode *head2) {
	if (head1 == NULL || head2 == NULL) return NULL;
	int n1 = 0;
	for (ListNode* p = head1; p != NULL; p = p->next) n1++;
	int n2 = 0;
	for (ListNode* p = head2; p != NULL; p = p->next) n2++;
	
	ListNode* p1 = head1;
	ListNode* p2 = head2;
	if (n1 > n2) {
		for (int i = 0; i < n1-n2; ++i) p1 = p1->next;
	} else if (n1 < n2) {
		for (int i = 0; i < n2-n1; ++i) p2 = p2->next;
	}
	
	while (p1 != NULL && p2 != NULL && p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	
	if (p1 == p2 && p1 != NULL) return p1;
	else return NULL;
}
