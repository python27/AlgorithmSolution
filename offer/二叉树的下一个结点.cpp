#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cassert>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

/*
 * �����������ı���:
 * 1. ����ýڵ���NULL������NULL
 * 2. ����ýڵ���������ǿգ�����һ���ڵ�Ϊ�������е�"����"�ڵ�
 * 3. ����ýڵ��������Ϊ�գ��ҵ��丸�ڵ�
 *    3.1 �丸�ڵ�ΪNULL������NULL
 *    3.2 �ýڵ�Ϊ���ڵ�����ӣ��򸸽ڵ㼫Ϊ��һ���ڵ�
 *    3.3 �ýڵ�Ϊ���ڵ���к��ӣ���ڵ㲻�����ƣ�ֱ������3.1��3.2�����Ϊֹ
 */
TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == NULL) return NULL;
	// ���������գ�������ڵ�Ϊ��һ���ڵ�
	if (pNode->right != NULL) {
		TreeLinkNode* p = pNode->right;
		while (p->left != NULL) {
			p = p->left;
		}
		return p;
	} else {
	// ������Ϊ��
		TreeLinkNode* parentNode = pNode->next;
		while (true) {
		    // 1. û�и��ڵ㣬Ҳ��û�к����ڵ�
		    if (parentNode == NULL) {
				return NULL;
		    } else {
		    	// 2. ���ڵ㲻�գ�ͬʱ��ǰ�ڵ��Ǹ��ڵ�����ӣ��򸸽ڵ�Ϊ��һ���ڵ�
		    	if (parentNode->left == pNode) {
		    		return parentNode;
				} else {
					// 3. ���ڵ㲻�գ�ͬʱ��ǰ�ڵ��Ǹ��ڵ���Һ��ӣ���ָ������
					pNode = parentNode;
					parentNode = pNode->next;
				}
			}
	    }
	}
	return NULL;
}
