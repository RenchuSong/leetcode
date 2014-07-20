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

void print(ListNode* node) {
	if (node == NULL) return;
	cout << node->val << " ";
	print(node->next);
}

class Solution {
public:
	// Combine and result the last ListNode*
    ListNode* combine(ListNode* pre, ListNode* left, ListNode* right, int len) {
		int p = 0, q = 0;
		for (int i = 0; i < len * 2; ++i) {
			if (p == len) {
				pre->next = right;
				if (right != NULL) right = right->next;
				++q;
			} else if (q == len) {
				pre->next = left;
				left = left->next;
				++p;
			} else if (left->val < right->val) {
				pre->next = left;
				left = left->next;
				++p;
			} else {
				pre->next = right;
				right = right->next;
				++q;
			}
			pre = pre->next;
		}
		return pre;
	}
	
	ListNode *sortList(ListNode *head) {
        int n = 0;
		ListNode* tmp = head;
		int big = -1;
		if (head != NULL) big = head->val;
		while (tmp != NULL) {
			if (tmp->val > big) big = tmp->val;
			++n; tmp = tmp->next;
		}
		
		if (n < 2) return head;
		
		++big;
		int nn = 1, exp = 0;
		while (nn < n) {
			nn *= 2;
			++exp;
		}
		tmp = head;
		for (int i = n; i < nn; ++i) {
			ListNode* mid = new ListNode(big);
			mid->next = tmp;
			tmp = mid;
		}
		
		ListNode* vh = new ListNode(-1);
		vh->next = tmp;
		
		for (int loop = 0; loop < exp; ++loop) {
			int len = 1 << loop;
			int time = nn / len / 2;
			//cout << time << endl;
			//if (loop == 2)
			//	print(vh);cout << endl;
			ListNode *pre = vh, *nextStart = vh->next, *left = NULL, *right = NULL;
			for (int i = 0; i < time; ++i) {
				left = right = nextStart;
				for (int j = 0; j < len; ++j) right = right->next;
				if (i < time - 1) {
					nextStart = right;
					for (int j = 0; j < len; ++j) nextStart = nextStart->next;
				}
				//if (i == 0) cout << left->val << " " << right->val << endl;
				pre = combine(pre, left, right, len);
				//cout << pre->val << "---" << endl;
			}
			pre->next = NULL;
		}
		
		tmp = vh;
		for (int i = 0; i < n; ++i) tmp = tmp->next;
		tmp->next = NULL;
		
		return vh->next;
    }
};

int main(int argc, const char * argv[])
{
	ListNode* p1 = new ListNode(10);
	ListNode* p2 = new ListNode(6);
	ListNode* p3 = new ListNode(5);
	ListNode* p4 = new ListNode(40);
	ListNode* p5 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	//print(p1);
	//(new Solution())->sortList(p1);
	print((new Solution())->sortList(p1));
	cout << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

