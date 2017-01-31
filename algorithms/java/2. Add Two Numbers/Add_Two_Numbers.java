/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int len1 = 0, len2 = 0;
        for(ListNode p = l1; p != null; p = p.next, len1++);
        for(ListNode p = l2; p != null; p = p.next, len2++);
        if(len1 > len2) {
        	ListNode t = l2;
        	while(t.next != null) t = t.next;
        	for(int i = len2; i < len1; i++) {
        		t.next = new ListNode(0);
        		t = t.next;
        	}
        }
        else {
        	ListNode t = l1;
        	while(t.next != null) t = t.next;
        	for(int i = len1; i < len2; i++) {
        		t.next = new ListNode(0);
        		t = t.next;
        	}
        }
        ListNode ans = new ListNode(l1.val + l2.val), head;
        head = ans;
        for(l1 = l1.next, l2 = l2.next; l1 != null && l2 != null; l1 = l1.next, l2 = l2.next) {
        	ans.next = new ListNode(l1.val + l2.val);
        	ans = ans.next;
        }
        for(ListNode p = head; p != null; p = p.next) {
        	if(p.val >= 10) {
        		p.val %= 10;
        		if(p.next != null) p.next.val++;
        		else p.next = new ListNode(1);
        	}
        }
        return head;
    }
}
