class Solution {
public:
    int dfs(int cur, vector<bool>& hasApple) {
        vis[cur] = true;
	int ans = -1;
        for (int i = 0; i < mp[cur].size(); ++i) {
	    if (!vis[mp[cur][i]]){
	        int tmp = dfs(mp[cur][i],hasApple);
		if (tmp >= 0) {
		    if(ans < 0) ans = tmp + 2;
		    else ans += (tmp + 2);
		}
	    }
	}
	if (hasApple[cur] && ans < 0) ans = 0;
	return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        mp.resize(n);
	for (int i = 0; i < edges.size(); ++i) {
	    mp[edges[i][0]].push_back(edges[i][1]);
	    mp[edges[i][1]].push_back(edges[i][0]);
	}
	vis.resize(n,false);
	return dfs(0,hasApple);
    }
    vector<vector<int>> mp;
    vector<bool> vis;
};
