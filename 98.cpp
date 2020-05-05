class Solution {
public:
    void dfs(TreeNode* cur, long u, long l) {
        if (cur == NULL) return;
        if (!ans) return;
        if (cur->val > l && cur->val < u) {
            dfs(cur->left,cur->val,l);
            dfs(cur->right,u,cur->val);
        } else {
            ans = false;
        }
    }
    bool isValidBST(TreeNode* root) {
        ans = true;
        dfs(root,2147483648,-2147483649);
        return ans;
    }
    bool ans;
};
