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
        vector<ListNode*> l1_st;
        vector<ListNode*> l2_st;
	ListNode* tmp = l1;
	while (tmp != NULL) {
	    l1_st.push_back(tmp);
	    tmp = tmp->next;
	}
	tmp = l2;
	while (tmp != NULL) {
	    l2_st.push_back(tmp);
	    tmp = tmp->next;
	}
	tmp = NULL;
	int l , r, pre = 0;
	ListNode* res = NULL;
	ListNode* cur = NULL;
	while (!l1_st.empty() || !l2_st.empty() || pre != 0) {
	    l = 0;
	    if (!l1_st.empty()) {
	        l = l1_st.back()->val;
		l1_st.pop_back();
	    }
	    r = 0;
	    if (!l2_st.empty()) {
	        r = l2_st.back()->val;
		l2_st.pop_back();
	    }
	    tmp = new ListNode((l+r+pre)%10);
	    pre = (l+r+pre)/10;
	    if (res == NULL) {
	        res = tmp;
	    } else {
	        tmp->next = res;
		res = tmp;
	    }
	}
	return res;
    }
};
