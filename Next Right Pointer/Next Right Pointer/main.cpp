//
//  main.cpp
//  Next Right Pointer
//
//  Created by Renchu Song on 4/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
		if (root == NULL) return;
		if (root->left != NULL) {
			TreeLinkNode *l = root->left, *r = root->right;
			l->next = r;
			while (l->right != NULL) {
				l = l->right;
				r = r->left;
				l->next = r;
			}
		}
		connect(root->left);
		connect(root->right);
    }
};

void print(TreeLinkNode* node) {
	if (node == NULL) return;
	cout << ((node->next == NULL) ? -1 : node->next->val) << endl;
	print(node->left);
	print(node->right);
}

int main(int argc, const char * argv[])
{

	TreeLinkNode* one = new TreeLinkNode(1);
	TreeLinkNode* two = new TreeLinkNode(2);
	TreeLinkNode* three = new TreeLinkNode(3);
	TreeLinkNode* four = new TreeLinkNode(4);
	TreeLinkNode* five = new TreeLinkNode(5);
	TreeLinkNode* six = new TreeLinkNode(6);
	TreeLinkNode* seven = new TreeLinkNode(7);
	
	
	one->left = two;
	one->right = three;
	two->left = four;
	two->right = five;
	three->left = six;
	three->right = seven;
	
	(new Solution())->connect(one);
	print(one);

    return 0;
}

