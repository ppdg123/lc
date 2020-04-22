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
    void dfs(TreeNode* cur, int level) {
        if(cur == NULL) return;
	if(ans.size() < level) ans.push_back(cur->val);
	dfs(cur->right,level+1);
	dfs(cur->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,1);
	return ans;
    }
    vector<int> ans;
};
