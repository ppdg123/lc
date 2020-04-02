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
    int pmax(int a , int b) {return a>b?a:b;}
    int dfs(Treenode * cur) {
        if (cur == NULL) return 0;
	int l = dfs(cur->left);
	int r = dfs(cur->right);
	int tmp = cur->val;
	if(l>0) tmp += l;
	if(r>0) tmp += r;
	if (tmp > ans) ans = tmp;
	l = pmax(l,r);
	if (l > 0) {
	    return cur->val + l;
	} else {
	    return cur->val;
	}

    }
    int maxPathSum(TreeNode* root) {
        ans = root->val;
	dfs(root);
	return ans;
    }
    int ans;
};
