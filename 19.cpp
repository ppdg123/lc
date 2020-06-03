class Solution {
public:
    int dfs(ListNode * cur, int n) {
        if (cur == NULL) reutrn 0;
	int l = dfs(cur->next,n);
	if (l == n) {
	    cur->next = cur->next->next;
	}
	return l+1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode f;
	f.next = head;
        dfs(&f,n);
	return f.next;
    }
};
