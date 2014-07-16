//
//  main.cpp
//  Binary Tree Zigzag Level Order Traversal
//
//  Created by Renchu Song on 15/7/14.
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
		if (root != NULL) {
			vector<TreeNode*> pre, now;
			now.push_back(root);
			while (!now.empty()) {
				vector<int> item;
				for (TreeNode* tmp: now) item.push_back(tmp->val);
				result.push_back(item);
				pre = now;
				now.clear();
				for (TreeNode* tmp: pre) {
					if (tmp->left != NULL) now.push_back(tmp->left);
					if (tmp->right != NULL) now.push_back(tmp->right);
				}
			}
			for (int i = 1; i < result.size(); i += 2)
				reverse(result[i].begin(), result[i].end());
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{
	TreeNode *r1 = new TreeNode(3);
	TreeNode *r2 = new TreeNode(9);
	TreeNode *r3 = new TreeNode(20);
	TreeNode *r4 = new TreeNode(15);
	TreeNode *r5 = new TreeNode(7);
//	r1->left = r2;
//	r1->right = r3;
//	r3->left = r4;
//	r3->right = r5;
	
	vector<vector<int> > tra = (new Solution())->zigzagLevelOrder(NULL);
	for (vector<int> item: tra) {
		for (int i: item) cout << i << " "; cout << endl;
	}
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

