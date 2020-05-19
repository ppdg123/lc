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
    struct node {int idx,val;};
    vector<int> nextLargerNodes(ListNode* head) {
	ListNode * cur = head;
	int cnt = 0;
	while(cur != NULL) {
	    cnt ++;
	    cur = cur->next;
	}
	vector<int> ans(cnt,0);
	vector<struct node> c;
	cur = head;
	cnt = 0;
	while(cur != NULL) {
	    for (int i = c.size()-1; i>=0; i--) {
	        if (c[i].val < cur->val) {
		    ans[c[i].idx] = cur->val;
		    c.pop_back();
		} else {
		    break;
		}
	    }
	    struct node tmp;
	    tmp.idx = cnt;
	    tmp.val = cur->val;
	    c.push_back(tmp);
	    cnt++;
	    cur = cur->next;
	}
	return ans;
    }
};
