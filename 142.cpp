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
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> s;
	ListNode* ptr = head;
	while (ptr != NULL) {
	    if (s.find(ptr) == s.end()) {
	        s.insert(ptr);
		ptr = ptr->next;
	    } else return ptr;
	}
	return NULL;
    }
};
