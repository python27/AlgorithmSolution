#include <iostream>
#include <string>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isMirror(TreeNode* root1, TreeNode* root2)
{
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL && root2 != NULL) return false;
    if (root1 != NULL && root2 == NULL) return false;
    return root1->val == root2->val &&
           isMirror(root1->right, root2->left) &&
           isMirror(root1->left,  root2->right);
}

bool isSymmetric(TreeNode* root)
{
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    //root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    //root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool ans = isSymmetric(root);
    cout << ans << endl;
    return 0;
}
