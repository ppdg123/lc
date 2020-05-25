class Solution {
public:
    ListNode * qs(ListNode * cur,int n) {
        if (cur == NULL || n = 0) return NULL;
	if (n==1) return cur;
	ListNode * l = cur, * r = cur;
	int m = n/2;
	while(m) {r = r->next;m--;}
	l = qs(l,n/2);
	r = qs(r,n-n/2);
	ListNode flag;
	cur = &flag;
	int ll = 0,rr = 0;
	while (ll < n/2 || rr < (n-n/2)) {
	    if (ll == n/2) {
	        cur->next = r;
		r = r->next;
		rr++;
		cur = cur->next;
		continue;
	    }
	    if (rr == (n-n/2)) {
	        cur->next = l;
		l = l->next;
		ll++;
		cur = cur->next;
		continue;
	    }
	    if (l->val < r->val) {
	        cur->next = l;
		l = l->next;
		ll ++;
		cur = cur->next;
	    } else {
	        cur->next = r;
		r = r->next;
		rr++;
		cur = cur->next;
	    }
	}
	cur->next = NULL;
	return flag.next;
    }
    ListNode* sortList(ListNode* head) {
        int n = 0;
	ListNode * cur = head;
	while(cur != NULL) {n++;cur=cur->next;}
	return qs(head,n);
    }
};
