//
//  main.cpp
//  Add Two Numbers
//
//  Created by Renchu Song on 10/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int bit = 0;
		ListNode* head = new ListNode(-1), *now = head;
		while (l1 != NULL || l2 != NULL) {
			int a = (l1 == NULL ? 0 : l1->val), b = (l2 == NULL ? 0 : l2->val);
			l1 = (l1 == NULL ? l1 : l1->next);
			l2 = (l2 == NULL ? l2 : l2->next);
			now->next = new ListNode((a + b + bit) % 10);
			now = now->next;
			bit = (a + b + bit) / 10;
		}
		if (bit > 0) now->next = new ListNode(bit);
		return head->next;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

