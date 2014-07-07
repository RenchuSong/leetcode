//
//  main.cpp
//  Minimum Depth of Binary Tree
//
//  Created by Renchu Song on 6/7/14.
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
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
		int left = minDepth(root->left), right = minDepth(root->right);
		int down = root->left == NULL ? (root->right == NULL ? 0 : right) : (root->right == NULL ? left : min(left, right)) ;
		return down + 1;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

