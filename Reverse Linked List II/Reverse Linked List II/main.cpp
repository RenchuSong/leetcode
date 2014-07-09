//
//  main.cpp
//  Reverse Linked List II
//
//  Created by Renchu Song on 8/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace::std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
		if (head == NULL || m == n) return head;
        ListNode *pre = NULL, *mPtr = head;
		for (int i = 1; i < m; ++i) {
			pre = mPtr;
			mPtr = mPtr->next;
		}
		ListNode *nPtr = mPtr, *nnPtr = nPtr->next, *nnnPtr = nnPtr->next;
		for (int i = m; i < n; ++i) {
			nnPtr->next = nPtr;
			nPtr = nnPtr;
			nnPtr = nnnPtr;
			if (nnnPtr != NULL) nnnPtr = nnnPtr->next;
		}
		if (pre == NULL) head = nPtr;
		else pre->next = nPtr;
		mPtr->next = nnPtr;
		return head;
    }
};

void print(ListNode* node) {
	if (node == NULL) return;
	cout << node->val << " ";
	print(node->next);
}

int main(int argc, const char * argv[])
{
	ListNode* n1 = new ListNode(3), *n2 = new ListNode(5);
	n1->next = n2;
	print((new Solution())->reverseBetween(n1, 1, 2));
    return 0;
}

