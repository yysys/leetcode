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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        for(ListNode* p = l1; p; len1++, p = p->next);
        for(ListNode* p = l2; p; len2++, p = p->next);
        if(len1 > len2) {
        	ListNode *t = l2;
        	while(t->next) t = t->next;
        	for(int i = len2; i < len1; i++) {
        		ListNode *p = new ListNode(0);
        		t->next = p;
        		t = p;
        	}
        }
        else {
        	ListNode *t = l1;
        	while(t->next) t = t->next;
        	for(int i = len1; i < len2; i++) {
        		ListNode *p = new ListNode(0);
        		t->next = p;
        		t = p;
        	}
        }
        ListNode *p = new ListNode(l1->val + l2->val), *head;
        head = p;
		for(l1 = l1->next, l2 = l2->next; l1 && l2; l1 = l1->next, l2 = l2->next) {
			p->next = new ListNode(l1->val + l2->val);
			p = p->next;
		}
		for(p = head; p; p = p->next)
			if(p->val >= 10) {
				p->val %= 10;
				if(p->next) p->next->val++;
				else p->next = new ListNode(1);
			}
		return head;	
    }
};
