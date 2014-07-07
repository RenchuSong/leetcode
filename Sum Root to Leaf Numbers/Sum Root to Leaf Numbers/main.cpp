//
//  main.cpp
//  Sum Root to Leaf Numbers
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void dfs(TreeNode *node, int num, int& result) {
		if (node->left == NULL && node->right == NULL) {
			result += num;
			return;
		}
		if (node->left != NULL) dfs(node->left, num * 10 + node->left->val, result);
		if (node->right != NULL) dfs(node->right, num * 10 + node->right->val, result);
	}
    int sumNumbers(TreeNode *root) {
		if (root == NULL) return 0;
		int result = 0;
        dfs(root, root->val, result);
		return result;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

