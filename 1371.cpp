class Solution {
public:
    int findTheLongestSubstring(string s) {
        int vis[2][2][2][2][2];
	int ans = 0;
	int a = 0, e = 0, i = 0, o = 0, u = 0;
	memset(vis,0,sizeof(vis));
	for (int j = 0; j < s.size(); ++j) {
	    if (s[j] == 'a') a = 1-a;
	    if (s[j] == 'e') e = 1-e;
	    if (s[j] == 'i') i = 1-i;
	    if (s[j] == 'o') o = 1-o;
	    if (s[j] == 'u') u = 1-u;
	    if (!(a || e || i || o || u)) {
	        if ((j+1) > ans) ans = j+1;
	    }
	    if (vis[a][e][i][o][u]) {
	         if ((j+1-vis[a][e][i][o][u]) > ans) ans = (j+1-vis[a][e][i][o][u]);
	    } else {
	        vis[a][e][i][o][u] = j+1;
	    }
	}
	return ans;
    }
};
