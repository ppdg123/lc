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
    void check(TreeNode* s, TreeNode* t){
        if(s == NULL && t==NULL) return;
	if(!ck) return;
	if(s == NULL || t == NULL){ 
	    ck = false;
	    return;
	}
	if(s->val != t->val) {
	    ck = false;
	    return;
	}
	check(s->left,t->left);
	check(s->right,t->right);
    }
    void dfs(TreeNode* cur, int target) {
        if(cur == NULL) return;
	if(ans) return;
	if(cur->val == target){
	    ck = true;
	    check(cur,tt);
	    ans = ck;
	    if(ans) return;
	}
	dfs(cur->left,target);
	if(ans) return;
	dfs(cur->right,target);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        tt = t;
	dfs(s,t->val);
        return ans;
    }
    bool ans;
    bool ck;
    TreeNode* tt;
};
