//
//  main.cpp
//  Insertion Sort List
//
//  Created by Renchu Song on 8/7/14.
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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) return NULL;
		ListNode *h = NULL, *t = NULL, *now = head, *next = head->next;
		while (now != NULL) {
			if (h == NULL) h = t = now; else {
				if (now->val <= h->val) {
					now->next = h; h = now;
				} else if (now->val >= t->val) {
					t->next = now; t = now;
				} else {
					ListNode* tmp = h;
					while (tmp->next->val < now->val) tmp = tmp->next;
					now->next = tmp->next; tmp->next = now;
				}
			}
			now = next; if (next != NULL) next = next->next;
		}
		t->next = NULL;
		return h;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

