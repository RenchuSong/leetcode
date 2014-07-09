//
//  main.cpp
//  Validate Binary Search Tree
//
//  Created by Renchu Song on 8/7/14.
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
	int now = 1 << 31;
    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;
		if (!isValidBST(root->left)) return false;
		if (root->val <= now) return false;
		now = root->val;
		if (!isValidBST(root->right)) return false;
		return true;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

