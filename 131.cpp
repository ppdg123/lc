class Solution {
public:
    bool is_p(string &str, int s, int e) {
        int m = (s + e)/2;
	while(s <= m){
	    if (str[s] != str[e]) return false;
	    s ++; e--;
	}
	return true;
    }
    void dfs(vector<vector<string>>&vis, vector<string>&path,int cur,int n) {
        if (cur >= n) {
	    ans.push_back(path);
	    return;
	}
	for (int i = 0; i < vis[cur].size(); ++i) {
	    path.push_back(vis[cur][i]);
	    dfs(vis,path,cur+vis[cur][i].size(),n);
	    path.pop_back();
	}
    }
    vector<vector<string>> partition(string s) {
        ans.clear();
        int n = s.size();
	vector<vector<string>> vis(n);
	for(int i = 0; i < n; ++i) {
	    for(int j = i; j < n; ++j) {
	        if(is_p(s,i,j)) {
		    vis[i].push_back(s.substr(i,j-i+1));
		}
	    }
	}
	vector<string> path;
	dfs(vis,path,0,n);
	return ans;
    }
    vector<vector<string>> ans;
};

