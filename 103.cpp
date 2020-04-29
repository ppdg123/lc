class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
	vector<TreeNode*> buf;
	int l = 0, r = 0;
	buf.push_back(root);
	bool od = true;
	while(l <= r) {
	    vector<int> tmp;
	    if (od) {
	        for(int i = l; i <= r; ++i) {
		    if (buf[i]->left != NULL)
		        buf.push_back(buf[i]->left);
		    if (buf[i]->right != NULL)
		        buf.push_back(buf[i]->right);
		    tmp.push_back(buf[i]->val);
		}
	    } else {
	        for(int i = r; i >= l; --i) {
		    tmp.push_back(buf[i]->val);
		}
	        for(int i = l; i <= r; ++i) {
		    if (buf[i]->left != NULL)
		        buf.push_back(buf[i]->left);
		    if (buf[i]->right != NULL)
		        buf.push_back(buf[i]->right);
		}
	    }
	    od = !od;
	    ans.push_back(tmp);
	    l = r+1;
	    r = buf.size()-1;
	}
	return ans;
    }
};

