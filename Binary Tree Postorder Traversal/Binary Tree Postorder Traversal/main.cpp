//
//  main.cpp
//  Binary Tree Postorder Traversal
//
//  Created by Renchu Song on 6/7/14.
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
	// Recursive. Fuck! O(NlogN) because of reinsert into the vector in each level
    vector<int> postorderTraversalRecursive(TreeNode *root) {
		vector<int> result;
		if (root != NULL) {
			vector<int> left = postorderTraversalRecursive(root->left);
			for (int i = 0; i < left.size(); ++i) result.push_back(left[i]);
			vector<int> right = postorderTraversalRecursive(root->right);
			for (int i = 0; i < right.size(); ++i) result.push_back(right[i]);
			result.push_back(root->val);
		}
		return result;
    }
	
	// Non-recursive solution.
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<int> status;			// 0: not visited left; 1: not visited right;  2: done
		stack<TreeNode*> mockStack;
		
		if (root != NULL) {
			mockStack.push(root);
			status.push(0);
		}
		
		while (!mockStack.empty()) {
			TreeNode* current = mockStack.top();
			int curStat = status.top();
			if (curStat == 0) {
				status.pop();
				status.push(1);
				if (current->left != NULL) {
					mockStack.push(current->left);
					status.push(0);
				}
			} else if (curStat == 1) {
				status.pop();
				status.push(2);
				if (current->right != NULL) {
					mockStack.push(current->right);
					status.push(0);
				}
			} else {
				result.push_back(mockStack.top()->val);
				status.pop();
				mockStack.pop();
			}
		}
		
		return result;
    }
};

int main(int argc, const char * argv[])
{
	TreeNode* one = new TreeNode(1);
	TreeNode* two = new TreeNode(2);
	TreeNode* three = new TreeNode(3);
	TreeNode* four = new TreeNode(4);
	TreeNode* five = new TreeNode(5);
	
	one->left = two;
	one->right = three;
	three->left = four;
	four->right = five;
	
	vector<int> preorder = (new Solution())->postorderTraversal(one);
	for (int i = 0; i < preorder.size(); ++i) {
		cout << preorder[i] << " ";
	}
	cout << endl;
    return 0;
}