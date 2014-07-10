//
//  main.cpp
//  Reorder List
//
//  Created by Renchu Song on 9/7/14.
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
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL) return;
        ListNode *v = new ListNode(-1);
        v->next = head;
        ListNode *f = v, *s = v;
        int n = 0;
        for (; f != NULL; ) {
        	s = s->next;
        	f = f->next;
        	if (f != NULL) f = f->next;
        	++n;
        }
        f = s->next;
        int m = 0;
        ListNode *pre = s, *tmp;
        while (f != NULL) {
        	tmp = f->next;
        	f->next = pre;
        	pre = f;
        	f = tmp;
        	++m;
        }
        f = pre;
        ListNode *tail = (n > m) ? s : s->next;
        s = head;
        for (int i = 0; i < n + m; ++i) {
        	if (i % 2 == 0) {
        		tmp = s->next;
        		s->next = f;
        		s = tmp;
        	} else {
        		tmp = f->next;
        		f->next = s;
        		f = tmp;
        	}
        }
        tail->next = NULL;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

