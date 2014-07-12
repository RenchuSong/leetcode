//
//  main.cpp
//  Binary Tree Maximum Path Sum
//
//  Created by Renchu Song on 11/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace::std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxLength(TreeNode *node, int &result) {
		if (node == NULL) return 0;
		int left = maxLength(node->left, result);
		int right = maxLength(node->right, result);
		if (left + node->val + right > result) result = left + node->val + right;
		return max(0, max(left, right) + node->val);
	}
	
	void revisit(TreeNode* root, int &result) {
		if (root == NULL) return;
		if (root->val > result) result = root->val;
		revisit(root->left, result);
		revisit(root->right, result);
	}
	
    int maxPathSum(TreeNode *root) {
        int result = 0;
		maxLength(root, result);
		if (result == 0) {
			result = 1 << 31;
			revisit(root, result);
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{
	TreeNode *a = new TreeNode(-3), *b = new TreeNode(2), *c = new TreeNode(3);
	//a->left = b; a->right = c;
	cout << (new Solution())->maxPathSum(a) << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

