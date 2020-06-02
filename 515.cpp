class Solution {
public:
    vector<int> ans;
    void dfs(TreeNode * cur, int h) {
        if(cur == NULL) return;
	if (h >= ans.size()) ans.push_back(cur->val);
	else if (ans[h] < cur->val) ans[h] = cur->val;
	dfs(cur->left,h+1);
	dfs(cur->right,h+1);
    }
    vector<int> largestValues(TreeNode* root) {
        dfs(root,0);
	return ans;
    }
};
