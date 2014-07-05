//
//  main.cpp
//  Balanced Binary Tree
//
//  Created by Renchu Song on 5/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// Recursion in recursion
	int depth(TreeNode* node) {
		if (node == NULL) return 0;
		int l = depth(node->left), r = depth(node->right);
		return l > r ? l + 1 : r + 1;
	}
    
	bool isBalancedDoubleRecursive(TreeNode *root) {
        if (root == NULL) return true;
		int diff = depth(root->left) - depth(root->right);
		return isBalancedDoubleRecursive(root->left) && isBalancedDoubleRecursive(root->right) && diff < 2 && diff > -2;
    }
	
	// One recursion
	int depthBetter(TreeNode* node) {
		if (node == NULL) return 0;
		int l = depthBetter(node->left), r = depthBetter(node->right);
		return (l < 0 || r < 0) ? -1 : (l - r > 1 || l - r < -1) ? -1 : l > r ? l + 1 : r + 1;
	}
	
	bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
		int diff = depthBetter(root);
		return diff > -1;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

