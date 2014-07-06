//
//  main.cpp
//  Symmetric Tree
//
//  Created by Renchu Song on 5/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// Recursive
	bool judgeSymmetricRecursive(TreeNode* left, TreeNode* right) {
		if (left == NULL && right == NULL) return true;
		if (left == NULL || right == NULL) return false;
		if (left->val != right->val) return false;
		return judgeSymmetricRecursive(left->left, right->right) && judgeSymmetricRecursive(left->right, right->left);
	}
	
	bool isSymmetricRecursive(TreeNode *root) {
		if (root == NULL) return true;
        return judgeSymmetricRecursive(root->left, root->right);
    }
	
	//Iterative
	bool isSymmetric(TreeNode *root) {
		if (root == NULL) return true;
        stack<int> status;					// status: 0, none, 1, left visited, 2 right visited
		stack<TreeNode*> first, second;
		status.push(0);
		first.push(root->left);
		second.push(root->right);
		while (!first.empty()) {
			TreeNode* l = first.top(), *r = second.top();
			if (l == NULL && r == NULL) {
				status.pop(); first.pop(); second.pop();
			} else if (l == NULL || r == NULL) {
				return false;
			} else {
				if (l->val != r->val) return false;
				if (status.top() == 0) {
					status.pop();
					status.push(1);
					status.push(0);
					first.push(l->left);
					second.push(r->right);
				} else if (status.top() == 1) {
					status.pop();
					status.push(2);
					status.push(0);
					first.push(l->right);
					second.push(r->left);
				} else {
					status.pop(); first.pop(); second.pop();
				}
			}
		}
		return true;
    }
};

int main(int argc, const char * argv[])
{
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}
