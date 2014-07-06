//
//  main.cpp
//  Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
		if (head->next == head) return head;
		ListNode *now = head, *next = head;

		do {
			if (next->next == NULL) return NULL;
			if (next->next->next == NULL) return NULL;
			next = next->next->next;
			now = now->next;
		} while (now != next);
		
		next = head;
		while (next != now) {
			next = next->next;
			now = now->next;
		}
		return now;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

