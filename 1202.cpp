class Solution {
public:
    void dfs(vector<vector<int>>& mp, vector<bool>& vis, int cur) {
        if (!vis[cur]) ans.push_back(cur);
	vis[cur] = true;
	for (int i = 0; i < mp[cur].size(); ++i) {
	    if(!vis[mp[cur][i]]) dfs(mp,vis,mp[cur][i]);
	}
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
	vector<bool> vis(n,false);
	vector<vector<int>> mp(n,vector<int>(0));
	for (int i = 0; i < pairs.size(); ++i) {
	    mp[pairs[i][0]].push_back(pairs[i][1]);
	    mp[pairs[i][1]].push_back(pairs[i][0]);
	}
	for (int i = 0; i<n; ++i) {
	    if(mp[i].size() > 0 && !vis[i]) {
	        ans.clear();
		dfs(mp,vis,i);
		sort(ans.begin(),ans.end());
		vector<char> cs;
		for (int j = 0; j< ans.size(); ++j) {
		    cs.push_back(s[ans[j]]);
		}
		sort(cs.begin(), cs.end());
		for (int j = 0; j< ans.size(); ++j) {
		    s[ans[j]] = cs[j];
		}
	    }
	}
	return s;
    }
    vector<int> ans;
};

