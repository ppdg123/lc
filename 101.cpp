class Solution {
public:
    bool dfs(TreeNode * l , TreeNode * r) {
        if (l == NULL && r == NULL) return true;
	if (l == NULL || r == NULL) return false;
	if (l->val != r->val) return false;
	return dfs(l->left,r->right)&&dfs(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root,root);
    }
};
