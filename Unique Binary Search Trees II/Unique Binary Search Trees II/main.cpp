//
//  main.cpp
//  Unique Binary Search Trees II
//
//  Created by Renchu Song on 7/7/14.
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
	vector<TreeNode *> generateTreesHelper(int l, int r) {
        vector<TreeNode *> result;
		if (l < r) {
			for (int i = l; i <= r; ++i) {
				vector<TreeNode *> left = generateTreesHelper(l, i - 1);
				vector<TreeNode *> right = generateTreesHelper(i + 1, r);
				if (!right.size())
					for (int j = 0; j < left.size(); ++j) {
						TreeNode* r = new TreeNode(i);
						r->left = left[j];
						result.push_back(r);
					}
				if (!left.size())
					for (int j = 0; j < right.size(); ++j) {
						TreeNode* r = new TreeNode(i);
						r->right = right[j];
						result.push_back(r);
					}
				for (int j = 0; j < left.size(); ++j) {
					for (int k = 0; k < right.size(); ++k) {
						TreeNode *r = new TreeNode(i);
						r->left = left[j];
						r->right = right[k];
						result.push_back(r);
					}
				}
			}
		} else if (l == r) {
			result.push_back(new TreeNode(l));
		}
		return result;
    }
	
    vector<TreeNode *> generateTrees(int n) {
		if (n == 0) {
			vector<TreeNode*> result;
			result.push_back(NULL);
			return result;
		}
        return generateTreesHelper(1, n);
    }
};

void print(TreeNode* r) {
	cout << r->val << " ";
	if (r->left) print(r->left);
	if (r->right) print(r->right);
}

int main(int argc, const char * argv[])
{
	vector<TreeNode *> result = (new Solution())->generateTrees(2);
	for (TreeNode* r : result) { print(r); cout << endl; }
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

