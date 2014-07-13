//
//  main.cpp
//  Recover Binary Search Tree
//
//  Created by Renchu Song on 12/7/14.
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
	TreeNode *p1, *p2, *pre;
	
	void work(TreeNode *node) {
		if (node == NULL) return;
		work(node->left);
		if (pre != NULL && pre->val > node->val) {
			if (p1 == NULL) {
				p1 = pre; p2 = node;
			} else p2 = node;
		}
		pre = node;
		
		work(node->right);
	}
	
    void recoverTree(TreeNode *root) {
        work(root);
		int tmp = p1->val;
		p1->val = p2->val;
		p2->val = tmp;
    }
};

void print(TreeNode *node) {
	if (node == NULL) return;
	print(node->left);
	std::cout << node->val << " ";
	print(node->right);
}

int main(int argc, const char * argv[])
{
	TreeNode *p1 = new TreeNode(0);
	TreeNode *p2 = new TreeNode(1);
	p1->left = p2;
	
	(new Solution())->recoverTree(p1);
	print(p1);
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

