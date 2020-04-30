/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(vector<ListNode *> cur, TreeNode* tc) {
        vector<ListNode*> nxt;
	if (ans) return;
	if (tc == NULL) return;
	for (int i = 0; i < cur.size(); ++i) {
	    if(cur[i] == NULL) {
	        ans = true;
		return;
	    }
	    if(cur[i]->val == tc->val) {
	        if (cur[i]->next != NULL)
	            nxt.push_back(cur[i]->next);
		else {
		    ans = true;
		    return;
		}
	    }
	}
	nxt.push_back(lroot);
	dfs(nxt,tc->left);
	if(ans) return;
	dfs(nxt,tc->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        ans = false;lroot = head;
	if (head == NULL) return true;
	dfs(head,root);
	return ans;
    }
    bool ans;
    ListNode * lroot;
};
