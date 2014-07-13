//
//  main.cpp
//  Copy List with Random Pointer
//
//  Created by Renchu Song on 12/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) return NULL;
		
		// Round 1: Duplicate
        RandomListNode *c = head;
		while (c != NULL) {
			RandomListNode *n = new RandomListNode(c->label);
			n->next = c->next;
			n->random = c->random;
			c->next = n;
			c = n->next;
		}
		
		// Round 2: Maintain Random
		c = head;
		while (c != NULL) {
			if (c->random != NULL)
				c->next->random = c->random->next;
			c = c->next->next;
		}
		
		// Round 3: Recover & Chain
		c = head;
		RandomListNode *tmp, *result = head->next;
		
		while (c != NULL) {
			if (c->next->next != NULL) {
				tmp = c->next->next;
				c->next->next = c->next->next->next;
				c->next = tmp;
				c = tmp;
			} else {
				c->next = NULL;
				c = NULL;
			}
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

