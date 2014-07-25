/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
		ListNode* l = head, *r = head;
		do {
			l = l->next;
			if (l == NULL) return false;
			r = r->next;
			if (r == NULL) return false;
			r = r->next;
			if (r == NULL) return false;	
		} while (l != r);
		return true;
    }
};