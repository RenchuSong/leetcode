//
//  main.cpp
//  Merge k Sorted Lists
//
//  Created by Renchu Song on 15/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode* v = new ListNode(-1), *tmp = v;
		while (l1 != NULL || l2 != NULL) {
			if (l1 == NULL) { tmp->next = l2; break; }
			if (l2 == NULL) { tmp->next = l1; break; }
			if (l1->val < l2->val) {
				tmp->next = l1; l1 = l1->next;
			} else {
				tmp->next = l2; l2 = l2->next;
			}
			tmp = tmp->next;
		}
		return v->next;
	}
	
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        while (lists.size() > 1) {
			vector<ListNode *> tmp;
			int n = (int)lists.size();
			for (int i = 0; i < n; i += 2) {
				ListNode* merge = mergeTwoLists(lists[i], i < n - 1 ? lists[i + 1] : NULL);
				tmp.push_back(merge);
			}
			lists = tmp;
		}
		if (lists.size() == 0) return NULL;
		return lists[0];
    }
};

int main(int argc, const char * argv[])
{
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(0);
	p2->next = new ListNode(7);
	ListNode *p3 = new ListNode(3);
	p3->next = new ListNode(5);
	
	vector<ListNode*> a {p1, p2, p3};
	ListNode* result = (new Solution())->mergeKLists(a);
	while (result != NULL) {
		cout << result->val << endl; result = result->next;
	}
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

