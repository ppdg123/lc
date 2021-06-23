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
    void dfs(TreeNode * cur, vector<int> & path, int sum, int target) {
        if (cur == nullptr) return;
	if (cur->left == nullptr && cur->right == nullptr) {
	    sum += cur->val;
	    if (sum == target) {
	        path.push_back(cur->val);
		ans.push_back(path);
		path.pop_back();
	    }
	    return;
	}
	path.push_back(cur->val);
	dfs(cur->left, path, sum + cur->val, target);
	dfs(cur->right, path, sum + cur->val, target);
	path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ans.clear();
	vector<int> path;
	dfs(root,path,0,targetSum);
	return ans;
    }
    vector<vector<int>> ans;
};
