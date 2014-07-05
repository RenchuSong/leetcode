//
//  main.cpp
//  Merge Two Sorted Lists
//
//  Created by Renchu Song on 5/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode* head;
		if (l1->val < l2->val) {
			head = l1;
			l1 = l1->next;
		} else {
			head = l2;
			l2 = l2->next;
		};
		ListNode* current = head;
		
		while (l1 != NULL || l2 != NULL) {
			if (l1 == NULL) {
				current->next = l2; break;
			}
			if (l2 == NULL) {
				current->next = l1; break;
			}
			if (l1->val < l2->val) {
				current->next = l1;
				l1 = l1->next;
			} else {
				current->next = l2;
				l2 = l2->next;
			};
			current = current->next;
		}
		return head;
    }
};

int main(int argc, const char * argv[])
{
    return 0;
}

