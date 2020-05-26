class Solution {
public:
    void dfs(TreeNode * t, int l) {
        if(t == NULL) return;
	ListNode * tmp = new ListNode(t->val);
	if (l >= ans.size()) {
	    ans.push_back(tmp);
	    ptr.push_back(tmp);
	} else {
	    ptr[l]->next = tmp;
	    ptr[l] = tmp;
	}
	dfs(t->left,l+1);
	dfs(t->right,l+1);
    }
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        dfs(tree,0);
	return ans;
    }
    vector<ListNode*> ans;
    vector<ListNode*> ptr;
};
