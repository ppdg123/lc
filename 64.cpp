class Solution {
    public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
	for (int i = 0; i < grid.size(); ++i) {
	    for (int j = 0; j < grid[0].size(); ++j) {
	        if (i == 0 && j == 0) dp[i][j] = grid[i][j];
		if (i == 0 && j > 0) dp[i][j] = grid[i][j] + dp[i][j-1];
		if (i > 0 && j == 0) dp[i][j] = grid[i][j] + dp[i-1][j];
		if (i > 0 && j > 0) dp[i][j] = grid[i][j] + (dp[i][j-1]>dp[i-1][j]?dp[i-1][j]:dp[i][j-1]);
	    }
	}
	return dp.back().back();
    }
};
