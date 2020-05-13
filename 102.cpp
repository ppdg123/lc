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
    void dfs(TreeNode * cur, int l) {
        if (cur == NULL) return;
	if (l > ans.size()) {
	    vector<int> tmp;
	    ans.push_back(tmp);
	}
	ans[l-1].push_back(cur->val);
	dfs(cur->left,l+1);
	dfs(cur->right,l+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root,1);
	return ans;
    }
    vector<vector<int>> ans;
};
