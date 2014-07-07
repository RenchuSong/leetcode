//
//  main.cpp
//  Remove Nth Node From End of List
//
//  Created by Renchu Song on 6/7/14.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (head == NULL) return NULL;
        ListNode *first = head, *second = head, *pre = head;
		for (int i = 1; i < n; ++i) second = second->next;
		if (second->next != NULL) {
			first = first->next; second = second->next;
		}
		while (second->next != NULL) {
			first = first->next; second = second->next;
			pre = pre->next;
		}
		if (pre == first) {
			pre = pre->next;
			delete head;
			return pre;
		}
		pre->next = first->next;
		delete first;
		return head;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

