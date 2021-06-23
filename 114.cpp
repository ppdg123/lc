/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode * cur) {
        if (cur == nullptr) return;
	if (pre != nullptr) {
	    pre->left = nullptr;
	    pre->right = cur;
	}
	TreeNode * l = cur->left;
	TreeNode * r = cur->right;
	pre = cur;
	dfs(l);
	dfs(r);
    }
    void flatten(TreeNode* root) {
        pre = nullptr;
	dfs(root);
    }
    TreeNode * pre;
};
