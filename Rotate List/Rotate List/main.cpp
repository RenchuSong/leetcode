//
//  main.cpp
//  Rotate List
//
//  Created by Renchu Song on 12/7/14.
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
	int listLen(ListNode* node) {
		int ans = 0;
		while (node != NULL) {
			++ans;
			node = node->next;
		}
		return ans;
	}
	
    ListNode *rotateRight(ListNode *head, int k) {
        int len = listLen(head);
		if (len < 2) return head;
		k = k % len;
		if (k == 0) return head;
		k = len - k;
		ListNode *pre = NULL, *now = head;
		for (int i = 0; i < k; ++i) {
			pre = now; now = now->next;
		}
		pre->next = NULL;
		pre = now;
		while (pre->next != NULL) pre = pre->next;
		pre->next = head;
		return now;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

