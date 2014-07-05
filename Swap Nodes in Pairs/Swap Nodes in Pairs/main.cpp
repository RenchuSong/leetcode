//
//  main.cpp
//  Swap Nodes in Pairs
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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL) return NULL;
		ListNode
		*first = head,
		*second = head->next,
		*third = second == NULL ? NULL : second->next,
		*fourth = third == NULL ? NULL : third->next,
		*result = second == NULL ? first : second;
		
		while (first != NULL) {
			if (second != NULL) {
				second->next = first;
				first->next = fourth != NULL ? fourth : third;
				first = third;
				second = fourth;
				third = second == NULL ? NULL : second->next;
				fourth = third == NULL ? NULL : third->next;
			} else break;
		}
		
		return result;
    }
};

void print(ListNode* node) {
	if (node == NULL) return;
	cout << node->val << endl;
	print(node->next);
}

int main(int argc, const char * argv[])
{
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(3);
	ListNode* d = new ListNode(4);
	ListNode* e = new ListNode(5);
	ListNode* f = new ListNode(6);
	a->next = b;
	b->next = c;
	c->next = d;
//	d->next = e;
//	e->next = f;
	
	print((new Solution())->swapPairs(a));
    return 0;
}

