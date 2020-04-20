class Solution {
public:
    void dfs(int a, int b, vector<vector<char>>& grid) {
        if (a<0 || a >= h || b < 0 || b >=w) return;
	if (grid[a][b] != '1') return;
	grid[a][b] = '2';
	dfs(a+1,b,grid);
	dfs(a-1,b,grid);
	dfs(a,b+1,grid);
	dfs(a,b-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        h = grid.size();
	if (h == 0) return 0;
	w = grid[0].size();
	int ans = 0;
	for (int i = 0; i< h; ++i) {
	    for(int j = 0; j < w; ++j) {
	        if (grid[i][j] == '1') {
		    ans ++;
		    dfs(i,j,grid);
		}
	    }
	}
	return ans;
    }
    int h,w;
};

