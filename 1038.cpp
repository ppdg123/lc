class Solution {
public:
    void dfs(TreeNode * cur,int & s) {
        if (cur == NULL) return;
        dfs(cur->right,s);
	s += cur->val;
	cur->val = s;
	dfs(cur->left,s);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int s = 0;
        dfs(root,s);
        return root;
    }
};
