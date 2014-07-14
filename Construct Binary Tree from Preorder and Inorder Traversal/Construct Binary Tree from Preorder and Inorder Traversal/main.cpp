//
//  main.cpp
//  Construct Binary Tree from Preorder and Inorder Traversal
//
//  Created by Renchu Song on 13/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* helper(vector<int> &preorder, vector<int> &inorder, int l, int r, int ll) {
		if (l > r) return NULL;
		int rv = preorder[ll];
		TreeNode* root = new TreeNode(rv);
		for (int i = l; i <= r; ++i) if (inorder[i] == rv) {
			root->left = helper(preorder, inorder, l, i - 1, ll + 1);
			root->right = helper(preorder, inorder, i + 1, r, ll + i - l + 1);
			break;
		}
		return root;
	}
	
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = (int)inorder.size();
		if (n == 0) return NULL;
		return helper(preorder, inorder, 0, n - 1, 0);
    }
};

void print(TreeNode* node) {
	if (node == NULL) { cout << -1 << " "; return; }
	print(node->left);
	cout << node->val << " ";
	print(node->right);
}

int main(int argc, const char * argv[])
{
	vector<int> in {1, 2};
	vector<int> post {2, 1};
	TreeNode* tree = (new Solution())->buildTree(in, post);
	print(tree);
	cout << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

