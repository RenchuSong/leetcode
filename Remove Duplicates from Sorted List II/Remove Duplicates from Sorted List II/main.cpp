//
//  main.cpp
//  Remove Duplicates from Sorted List II
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
		ListNode* v = new ListNode(0), *result = v, *now = head, *next;
		int val = head->val, dup = 0;
		while (now != NULL) {
			next = now->next;
			if (next == NULL || next->val > val) {
				if (!dup) {
					v->next = now;
					v = now;
				}
				dup = 0;
				if (next != NULL) val = next->val;
			} else dup = 1;
			now = next;
		}
		v->next = NULL;
		return result->next;
    }
};

int main(int argc, const char * argv[])
{
	ListNode * n1 = new ListNode(1);
	ListNode * n2 = new ListNode(1);
	ListNode * n3 = new ListNode(1);
	ListNode * n4 = new ListNode(2);
	ListNode * n5 = new ListNode(3);
	ListNode * n6 = new ListNode(4);
	ListNode * n7 = new ListNode(5);
	
	n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5;// n5->next = n6; n6->next = n7;
	ListNode* result = (new Solution())->deleteDuplicates(n1);
	int ans = 0;
	while (result != NULL) {
		++ans; result = result->next;
	}
	std::cout << ans << std::endl;
    return 0;
}

