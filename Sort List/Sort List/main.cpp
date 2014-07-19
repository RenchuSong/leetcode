//
//  main.cpp
//  Sort List
//
//  Created by Renchu Song on 17/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

int coun;

void print(ListNode* node) {
	if (node == NULL) return;
	--coun;
	if (coun < 0) return;
	cout << node->val << " ";
	print(node->next);
}

class Solution {
public:
	// Combine and result the last ListNode*
    ListNode* combine(ListNode* pre, ListNode* x, int n, ListNode* y, int m) {
		int p = 0, q = 0;
		for (int i = 0; i < n + m; ++i) {
			if (q == m) {
				pre->next = x;
				for (int j = i; j < n + m; ++j) {
					pre = pre->next;
				}
				break;
			} else if (p == n) {
				pre->next = y;
				for (int j = i; j < n + m; ++j) {
					pre = pre->next;
				}
				break;
			} else{
				cout << p << " " << q << endl;
				if (x->val < y->val) {
				++p;
				pre->next = x;
				x = x->next;
				pre = pre->next;
			} else {
				++q;
				pre->next = y;
				y = y->next;
				pre = pre->next;
			}
			}
		}
		return pre;
	}
	
	ListNode *sortList(ListNode *head) {
        int n = 0;
		ListNode* tmp = head;
		while (tmp != NULL) {
			++n; tmp = tmp->next;
		}
		
		if (n < 2) return head;
		
		ListNode* vh = new ListNode(-1);
		vh->next = head;
		
		int len = 1;
		while (len < n) {
			int p = n / (len * 2);
			int mod = n % (len * 2);

			ListNode* x = vh->next, *y = vh->next, *nextx = NULL;
			for (int i = 0; i < len; ++i) y = y->next;
			if (p > 1) {
				nextx = y;
				for (int i = 0; i < len; ++i) nextx = nextx->next;
			}
			ListNode* pre = vh;
			
			for (int i = 0; i < p; ++i) {
				pre = combine(pre, x, len, y, len);
				x = nextx;
				pre->next = nextx;
				y = x;
				if (i < p - 1 || mod > len)
					for (int i = 0; i < len; ++i) y = y->next;
				if (i < p - 1 || mod > len) {
					nextx = y;
					for (int i = 0; i < len; ++i) nextx = nextx->next;
				}
			}
			if (mod > len) {
				pre = combine(pre, x, len, y, mod - len);
			}
			len *= 2;
		}
		
		return vh->next;
    }
};

int main(int argc, const char * argv[])
{
	ListNode* p1 = new ListNode(10);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);
	ListNode* p4 = new ListNode(4);
	ListNode* p5 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	
	//(new Solution())->sortList(p1);
	print((new Solution())->sortList(p1));
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

