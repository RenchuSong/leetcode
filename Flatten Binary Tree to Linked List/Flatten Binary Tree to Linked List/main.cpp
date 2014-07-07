//
//  main.cpp
//  Flatten Binary Tree to Linked List
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
	TreeNode *preorder(TreeNode *node) {
		if (node == NULL) return NULL;
		TreeNode *left = node->left, *right = node->right,
		*llast = preorder(left), *rlast = preorder(right);
		node->left = NULL;
		if (llast != NULL) {
			node->right = left;
			llast->right = right;
		}
		return rlast ? rlast : (llast ? llast : node);
	}
	
    void flatten(TreeNode *root) {
        if (root == NULL) return;
		preorder(root);
    }
};

void print(TreeNode* node) {
	if (node == NULL) return;
	std::cout << node->val << " " << std::endl;
	print(node->right);
}

int main(int argc, const char * argv[])
{
	TreeNode *one = new TreeNode(1);
	TreeNode *two = new TreeNode(2);
	TreeNode *the = new TreeNode(3);
	TreeNode *fou = new TreeNode(4);
	TreeNode *fiv = new TreeNode(5);
	TreeNode *six = new TreeNode(6);
	
	one->left = two;
	one->right = fiv;
	two->left = the;
	two->right = fou;
	fiv->right = six;
	(new Solution())->flatten(one);
	
	print(one);
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}
