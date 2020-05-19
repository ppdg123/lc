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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int s = 0;
	ListNode f;
	f.next = head;
	f.val = 0;
	map<int, ListNode *> buf;
	map<ListNode * , int > pre;
	ListNode * cur = & f;
	while (cur != NULL) {
	    s += cur->val;
	    pre[cur] = s;
	    if(buf.find(s) != buf.end()) {
		 ListNode * t = buf[s]->next;
		 while (t != cur) {
		     buf.erase(pre[cur]);
		     t = t -> next;
		 }
	         buf[s]->next = cur->next;
	    } else {
	         buf[s] = cur;
	    }
	    cur = cur->next;
	}
	return f.next;
    }
};
