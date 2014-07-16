//
//  main.cpp
//  Convert Sorted List to Binary Search Tree
//
//  Created by Renchu Song on 15/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(ListNode* node, int n) {
		if (node == NULL || n == 0) return NULL;
		
		int r = n / 2 + n % 2;
		ListNode* tmp = node, *pre = NULL;

		for (int i = 1; i < r; ++i) {
			if (pre == NULL) pre = node;
			tmp = tmp->next;
		}
		TreeNode* root = new TreeNode(tmp->val);
		root->right = buildTree(tmp->next, n - r);
		root->left = buildTree(pre, r - 1);
		
		return root;
	}
	
    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
		ListNode *tmp = head;
		while (tmp != NULL) {
			++n; tmp = tmp->next;
		}
		return buildTree(head, n);
    }
};

void print(TreeNode *node) {
	if (node == NULL) return;
	print(node->left);
	cout << node->val << endl;
	print(node->right);
}

int main(int argc, const char * argv[])
{
	ListNode* p1 = new ListNode(3);
	ListNode* p2 = new ListNode(5);
	ListNode* p3 = new ListNode(8);
	p1->next = p2;
	p2->next = p3;
	print((new Solution())->sortedListToBST(p1));
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

