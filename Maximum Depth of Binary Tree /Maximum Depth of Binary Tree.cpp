/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
		if (root == NULL) return 0;
		int l = maxDepth(root->left);
		int r = maxDepth(root->right);
		if (l < r) l = r;
		return l + 1;
    }
};