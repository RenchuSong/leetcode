//
//  main.cpp
//  Remove Duplicates from Sorted List
//
//  Created by Renchu Song on 4/7/14.
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
		ListNode *current = head, *next = head->next;
		while (current != NULL) {
			while (next != NULL && next->val == current->val) {
				ListNode* tmp = next;
				next = next->next;
				delete tmp;
			}
			current->next = next;
			current = next;
			if (current != NULL) next = current->next;
		}
		return head;
    }
};

void print(ListNode* node) {
	while (node!= NULL) {
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
}

int main(int argc, const char * argv[])
{
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(1);
	ListNode* c = new ListNode(2);
	ListNode* d = new ListNode(3);
	ListNode* e = new ListNode(3);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	a = (new Solution())->deleteDuplicates(a);
	print(a);
    return 0;
}

