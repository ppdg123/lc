class Solution {
public:
    void dfs(int l, int r, int n) {
        if (l == n && r == n) {
	    res.push_back(ans);
	    return;
	}
        if (l < n) {
	    ans.push_back('(');
	    dfs(l+1,r,n);
	    ans.pop_back();
	}
	if (l > r && r < n) {
	    ans.push_back(')');
	    dfs(l,r+1,n);
	    ans.pop_back();
	}
    }
    vector<string> generateParenthesis(int n) {
        dfs(0,0,n);
	return res;
    }
    string ans;
    vector<string> res;
};
