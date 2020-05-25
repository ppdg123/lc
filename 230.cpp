class Solution {
public:
    int ans;
    void dfs(TreeNode * cur, int &k) {
        if(cur == NULL || k<=0) return;
	dfs(cur->left,k);
	k--;
	if (k == 0) {ans = cur->val; return;}
	dfs(cur->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
	return ans;
    }
};
