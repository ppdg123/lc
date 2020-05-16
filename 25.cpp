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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * pre = NULL, * cur = head, * tmp,*thead,*ttail,*phead=NULL,*ptail=NULL,*res=NULL;
        while (cur!=NULL) {
	    int kk = k;
	    bool f = true;
	    tmp = cur;
	    while(kk--) {
	        if (tmp == NULL) {
		    f = false;
		    break;
		}
		tmp = tmp->next;
	    } 
	    if(f) {
	        int kk = k;
		ttail = cur;
		pre = NULL;
		while(kk--) {
	            tmp = cur->next;
		    cur->next = pre;
		    pre = cur;
		    cur = tmp;
		}
		thead = pre;
	    } else {
	        thead = cur;
		cur = NULL;
	    }
	    if (ptail != NULL) {
	        ptail->next = thead;
	    } else {
	        res = thead;
	    }
	    phead = thead;
	    ptail = ttail;
	}
	return res;
    }
};
