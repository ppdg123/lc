class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        ListNode flag;
	ListNode * fp = &flag;
	fp->next = head;
	ListNode * pre = fp;
	ListNode * cur = head;
	ListNode * next = head->next;
	while(cur != nullptr) {
	    if (next == nullptr) cur = cur->next;
	    else {
	        ListNode * tmp = next->next;
		pre->next = next;
		next->next = cur;
		cur->next = tmp;
		pre = cur;
		cur = tmp;
		if (cur == nullptr) next = nullptr;
		else next = cur->next;
	    }
	}
	return fp->next;
    }
};
