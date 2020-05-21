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
    void dfs(TreeNode* cur) {
        if (cur == NULL) return;
	dfs(cur->left);
	ans.push_back(cur->val);
	dfs(cur->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
	return ans;
    }
    vector<int> ans;
};
