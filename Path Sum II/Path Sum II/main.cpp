//
//  main.cpp
//  Path Sum II
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
	vector<vector<int>> pathSumHelper(TreeNode *node, int sum) {
		vector<vector<int>> result;
		if (node->left == NULL && node->right == NULL && sum == node->val) {
			vector<int> one;
			one.push_back(node->val);
			result.push_back(one);
		} else {
			if (node->left != NULL) {
				vector<vector<int>> left = pathSumHelper(node->left, sum - node->val);
				for (int i = 0; i < left.size(); ++i) {
					left[i].push_back(node->val);
					result.push_back(left[i]);
				}
			}
			if (node->right != NULL) {
				vector<vector<int>> right = pathSumHelper(node->right, sum - node->val);
				for (int i = 0; i < right.size(); ++i) {
					right[i].push_back(node->val);
					result.push_back(right[i]);
				}
			}
		}
		return result;
	}
	
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
		if (root != NULL) {
			result = pathSumHelper(root, sum);
			for (int i = 0; i < result.size(); ++i) {
				reverse(result[i].begin(), result[i].end());
			}
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{
	TreeNode *a[10];
	a[0] = new TreeNode(5);
	a[1] = new TreeNode(4);
	a[2] = new TreeNode(8);
	a[3] = new TreeNode(11);
	a[4] = new TreeNode(13);
	a[5] = new TreeNode(4);
	a[6] = new TreeNode(7);
	a[7] = new TreeNode(2);
	a[8] = new TreeNode(5);
	a[9] = new TreeNode(1);
	
	a[0]->left = a[1];
	a[0]->right = a[2];
	a[1]->left = a[3];
	a[2]->left = a[4];
	a[2]->right = a[5];
	a[3]->left = a[6];
	a[3]->right = a[7];
	a[5]->left = a[8];
	a[5]->right = a[9];
	
	vector<vector<int>> r = (new Solution())->pathSum(a[0], 22);
	for (int i = 0; i < r.size(); ++i) {
		for (int j = 0; j < r[i].size(); ++j) cout << r[i][j] << " ";
		cout << endl;
	}
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

