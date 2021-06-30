/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void dfs(TreeNode * cur) {
        if(cur == nullptr) {
	    path += "|n";
	    return ;
	}
	path += "|";
	path += to_string(cur->val);
	dfs(cur->left);
	dfs(cur->right);
    }
    void sfd(TreeNode * father, bool dir, int &ptr, string &data) {
        if (data[ptr] == 'n') {
	    if (dir) father->left = nullptr;
	    else father->right = nullptr;
	    ptr += 2;
	    return;
	}
	int j = ptr;
	while(j < data.size() && data[j] != '|') ++j;
	int val = stoi(data.substr(ptr,j-ptr));
	ptr = j+1;
	if (dir) {
	    father->left = new TreeNode(val);
	    sfd(father->left,true,ptr,data);
	    sfd(father->left,false,ptr,data);
	} else {
	    father->right = new TreeNode(val);
	    sfd(father->right,true,ptr,data);
	    sfd(father->right,false,ptr,data);
	}
    }
    string serialize(TreeNode* root) {
        path = "";
	dfs(root);
	return path;
    }

    TreeNode* deserialize(string data) {
       TreeNode flag;
       int ptr = 1;
       sfd(&flag,true,ptr,data);
       return flag.left;
    }
    string path;
};

