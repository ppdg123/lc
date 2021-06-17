class Solution {
public:
    void dfs(int cur, vector<int> & buf, int k, int n) {
	if (buf.size()==k) {
	    ans.push_back(buf);
	    return;
	}
        if (cur > n ) return;
	dfs(cur + 1, buf, k, n);
	buf.push_back(cur);
	dfs(cur+1, buf, k, n);
	buf.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
	vector<int> buf;
        dfs(1,buf,k,n);
	return ans;
    }
    vector<vector<int>> ans;
};
