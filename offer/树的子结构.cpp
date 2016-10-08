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

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

/*
 * �����ĿҲ�ǱȽ�����˼����Ŀ
 * �������뵽��Ҫʹ�õݹ��㷨��⣬�ؼ�����������ж���root1Ϊ������
 * �Ƿ��ܹ���ȫ����root2Ϊ����������������Ҫ�ڶ����������ڶ�������ͬ��
 * ��Ҫ�ݹ�ķ�ʽ���бȽ����
 */
bool Tree1ContainTree2(TreeNode* root1, TreeNode* root2) {
	if (root1 == NULL && root2 == NULL) return true;
	if (root1 != NULL && root2 == NULL) return true;
	if (root1 == NULL && root2 != NULL) return false;
	
	return root1->val == root2->val &&
		   Tree1ContainTree2(root1->left, root2->left) &&
		   Tree1ContainTree2(root1->right, root2->right);
}

bool HasSubtree(TreeNode* root1, TreeNode* root2) {
	if (root2 == NULL) return false;
	if (root1 == NULL) return false;
	
	if (root1->val == root2->val) {
		bool root_ok = Tree1ContainTree2(root1, root2);
		if (root_ok) return true;
		bool left_ok = HasSubtree(root1->left, root2);
		if (left_ok) return true;
		bool right_ok = HasSubtree(root1->right, root2);
		return right_ok;
		
	} else {
		bool left_ok = HasSubtree(root1->left, root2);
		if (left_ok) return true;
		bool right_ok = HasSubtree(root1->right, root2);
		return right_ok;
	}
}
