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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
	ListNode * cur = head;
	if (head == NULL) return head;
	while(cur != NULL) {n++; cur = cur->next;}
	k = k%n;
	if (k == 0) return head;
	ListNode * lh, * lt, *rh, * rt;
	lh = head;
	lt = lh;
	k = n - k;
	k --;
	while (k--) {
	    lt = lt->next;
	}
	rh = lt->next;
	rt = rh;
	while (rt->next != NULL) rt = rt->next;
	lt->next = NULL;
	rt->next = lh;
	return rh;
    }
};
