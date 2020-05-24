class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l , r , pre = 0;
	ListNode flag;
	ListNode* cur = &flag;
	while(l1 != NULL || l2 != NULL) {
	    if (l1 != NULL) {l = l1->val; l1 = l1->next;}
	    else l = 0;
	    if (l2 != NULL) {r = l2->val; l2 = l2->next;}
	    else r = 0;
	    ListNode * tmp = new ListNode((l+r+pre)%10);
	    pre = (l+r+pre)/10;
	    cur->next = tmp;
	    cur = cur->next;
	}
	return flag.next;
    }
};
