//
//  main.cpp
//  Partition List
//
//  Created by Renchu Song on 7/7/14.
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *smallHead = NULL, *smallTail = NULL, *bigHead = NULL, *bigTail = NULL;
		ListNode *tmp = head;
		while (tmp != NULL) {
			ListNode* mid = tmp->next;
			if (tmp->val < x) {
				if (smallHead == NULL) smallHead = smallTail = tmp; else {
					smallTail->next = tmp;
					smallTail = tmp;
				}
			} else {
				if (bigHead == NULL) bigHead = bigTail = tmp; else {
					bigTail->next = tmp;
					bigTail = tmp;
				}
			}
			tmp = mid;
		}
		if (bigTail != NULL) bigTail->next = NULL;
		if (smallHead != NULL) {
			smallTail->next = bigHead;
			return smallHead;
		} else return bigHead;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

