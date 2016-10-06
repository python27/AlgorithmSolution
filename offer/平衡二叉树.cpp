#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * �ú����жϵ�ǰrootΪ�������Ƿ�ΪBST��ͬʱ����
 * ���������depth
 * 1. ע��ݹ����ʱ������Ҫ�����depthֵ
 */
bool BSTWithDepth(TreeNode* root, int& depth) {
	if (root == NULL) {
		depth = 0;
		return true;
	}
	int depth_left = 0, depth_right = 0;
	bool leftBST = BSTWithDepth(root->left, depth_left);
	bool rightBST = BSTWithDepth(root->right, depth_right);
	// ���ؽ��֮ǰ��Ҫ���depth��ֵ
	depth = max(depth_left, depth_right) + 1;
	
	return leftBST && rightBST && abs(depth_left - depth_right) <= 1;
}

bool IsBalanced_Solution(TreeNode* root) {
	int depth = 0;
	bool ok = BSTWithDepth(root, depth);
	return ok;
}
