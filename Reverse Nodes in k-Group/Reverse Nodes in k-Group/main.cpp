//
//  main.cpp
//  Reverse Nodes in k-Group
//
//  Created by Renchu Song on 16/7/14.
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL || k < 2) return head;
		ListNode *vh = new ListNode(-1);
		vh->next = head;
		ListNode *pre = vh;
		while (true) {
			ListNode* nextH = pre->next;
			
			if (nextH == NULL) break;
			ListNode* nextT = nextH;
			bool flag = true;
			for (int i = 1; i < k; ++i) {
				nextT = nextT->next;
				if (nextT == NULL) {
					flag = false; break;
				}
			}
			
			if (!flag) {
				pre->next = nextH;
				break;
			}
			
			ListNode* nextLoop = nextT->next;
			
			ListNode* tmp = nextH, *mm = tmp->next;
			for (int i = 0; i < k - 1; ++i) {
				ListNode* src = mm->next;
				mm->next = tmp;
				tmp = mm;
				mm = src;
			}
			
			pre->next = nextT;
			nextH->next = nextLoop;
			pre = nextH;
		}
		return vh->next;
    }
};

void print(ListNode* tmp) {
	if (tmp == NULL) return;
	cout << tmp->val << endl;
	print(tmp->next);
}

int main(int argc, const char * argv[])
{
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);
	ListNode* p4 = new ListNode(4);
	ListNode* p5 = new ListNode(5);
	ListNode* p6 = new ListNode(6);
	ListNode* p7 = new ListNode(7);
	ListNode* p8 = new ListNode(8);
	

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	p7->next = p8;
	
	ListNode* run = (new Solution())->reverseKGroup(p1, 10);

	print(run);
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

