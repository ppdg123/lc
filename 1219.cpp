class Solution {
public:
    void dfs(vector<vector<int>>& grid, int a, int b,int s) {
         if (a < 0 || a >= h) return;
	 if (b < 0 || b >= w) return;
	 if (vis[a][b] || grid[a][b] == 0) return;
	 vis[a][b] = true;
	 s += grid[a][b];
	 if (s > ans) ans = s;
	 dfs(grid,a+1,b,s);
	 dfs(grid,a-1,b,s);
	 dfs(grid,a,b+1,s);
	 dfs(grid,a,b-1,s);
	 vis[a][b] = false;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        ans = 0;
	h = grid.size();
	if (h ==0) return 0;
	w = grid[0].size();
	vis = vector<vector<bool>>(h,vector<bool>(w,false));
	for (int i = 0; i< h; ++i) {
	    for(int j = 0; j < w; ++j) {
	        if (grid[i][j] > 0 && !vis[i][j]) {
		    dfs(grid,i,j,0);
		}
	    }
	}
	return ans;
    }
    int ans;
    int h;
    int w;
    vector<vector<bool>> vis;
};
