#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

/*
 * ���ӵ�����ɾ������
 * 1. ע����һ���ڵ��Ƿ��뵱ǰ�ڵ��ظ���������ȫ��ͬ�ģ������Ҫflag���
 * 2. ȷ������Ҫɾ���������Ҫ����ɾ���ĸպ���head�Ľڵ�ʱ����Ҫ����
 *    ͷָ��
 */

ListNode* deleteDuplication(ListNode* head)
{
	if (head == NULL) return NULL;
	if (head->next == NULL) return head;
	
	ListNode* newHead = head;
	ListNode* prev = NULL;
	ListNode* p1 = head;
	while (p1 != NULL) {
		ListNode* p2 = p1->next;
		bool found = false;
		while (p2 != NULL && p2->val == p1->val) {
			found = true;
			p2 = p2->next;
		}
		
		if (!found) {
			prev = p1;
			p1 = p2;
		} else {
			if (prev == NULL) {
				prev = NULL;
				p1 = p2;
				newHead = p2;
			} else {
				prev->next = p2;
				p1 = p2;
			}
		}
		
	}

	return newHead;
}

void PrintList(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->next) {
		cout << " " << p->val;
	}
	cout << endl;
}

int main()
{
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);
	ListNode* p4 = new ListNode(3);
	ListNode* p5 = new ListNode(4);
	ListNode* p6 = new ListNode(4);
	ListNode* p7 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	ListNode* head = p1;
	
	cout << "List:" << endl;
	PrintList(head);
	
	ListNode* head2 = deleteDuplication(head);
	cout << "New List:" << endl;
	PrintList(head2);
	return 0;
}
