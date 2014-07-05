//
//  main.cpp
//  Convert Sorted Array to Binary Search Tree
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
	TreeNode* convertBST(vector<int> &num, int l, int r) {
		if (l > r) return NULL;
		int m = (l + r) / 2;
		TreeNode* node = new TreeNode(num[m]);
		node->left = convertBST(num, l, m - 1);
		node->right = convertBST(num, m + 1, r);
		return node;
	}
	
	TreeNode *sortedArrayToBST(vector<int> &num) {
		return convertBST(num, 0, (int)num.size() - 1);
    }
};

int main(int argc, const char * argv[])
{
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}
