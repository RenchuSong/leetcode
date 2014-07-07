//
//  main.cpp
//  Populating Next Right Pointers in Each Node II
//
//  Created by Renchu Song on 6/7/14.
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
        TreeLinkNode *node = root;
		while (node != NULL) {
			TreeLinkNode* first = NULL, *one = NULL, *two = NULL, *tmp = node;
			while (tmp != NULL) {
				if (tmp->left != NULL) {
					if (first == NULL) first = tmp->left;
					if (one == NULL) one = tmp->left;
					else if (two == NULL) two = tmp->left;
				}
				if (two != NULL) {
					one->next = two;
					one = two;
					two = NULL;
				}
				if (tmp->right != NULL) {
					if (first == NULL) first = tmp->right;
					if (one == NULL) one = tmp->right;
					else if (two == NULL) two = tmp->right;
				}
				if (two != NULL) {
					one->next = two;
					one = two;
					two = NULL;
				}
				tmp = tmp->next;
			}
			node = first;
		}
    }
};

int main(int argc, const char * argv[])
{
	TreeLinkNode* a[10];
	for (int i = 0; i < 10; ++i) a[i] = new TreeLinkNode(i);
	a[0]->left = a[1];
	a[0]->right = a[2];
	a[1]->left = a[3];
	a[2]->left = a[4];
	a[2]->right = a[5];
	//a[3]->left = a[6];
	//a[3]->right = a[7];
	a[4]->right = a[8];
	a[5]->right = a[9];
	(new Solution())->connect(a[0]);
	for (int i = 0; i < 10; ++i) cout << (a[i]->next == NULL ? -1 : a[i]->next->val )<< endl;
	std::cout << "Hello, World!\n";
    return 0;
}

