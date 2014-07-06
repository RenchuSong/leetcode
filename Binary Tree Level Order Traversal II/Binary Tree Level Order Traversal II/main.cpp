//
//  main.cpp
//  Binary Tree Level Order Traversal II
//
//  Created by Renchu Song on 5/7/14.
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
		if (root != NULL) {
			vector<int> one;
			vector<TreeNode*> f[2];
			f[0].clear(); f[1].clear();
			one.push_back(root->val);
			f[0].push_back(root);
			result.push_back(one);
			int level = 0;
			while (true) {
				int now = level % 2, next = (level + 1) % 2;
				f[next].clear();
				vector<int> node;
				for (int i = 0; i < f[now].size(); ++i) {
					if (f[now][i]->left != NULL) f[next].push_back(f[now][i]->left);
					if (f[now][i]->right != NULL) f[next].push_back(f[now][i]->right);
				}
				if (f[next].size() < 1) break;
				for (int i = 0; i < f[next].size(); ++i) node.push_back(f[next][i]->val);
				result.push_back(node);
				level++;
			}
		}
		reverse(result.begin(), result.end());
		return result;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

