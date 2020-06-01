class Solution {
public:
    bool dfs(TreeNode * cur) {
        if (cur == NULL) return false;
	bool l = dfs(cur->left);
	bool r = dfs(cur->right);
	if (!l) cur->left = NULL;
	if (!r) cur->right = NULL;
	return (l || r || (cur->val == 1));
    }
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
	return root;
    }
};
