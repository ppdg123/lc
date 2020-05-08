class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int h = matrix.size();
	if(h==0) return 0;
	int w = matrix[0].size();
        vector<int> tmp(w,0);
	vector<vector<int>> dp(h,tmp);
	int ans = 0;
	for(int i = 0; i < w; i++) {
	    if(matrix[0][i] == '1') {dp[0][i] = 1;ans = 1;}
	}
	for(int j = 0; j < h ; ++j) {
	    if(matrix[j][0] == '1') {dp[j][0] = 1;ans = 1;}
	}
	for(int i = 1; i < h; ++i) {
	    for(int j = 1; j < w; ++j){
	        if(matrix[i][j] == '1') {
		    int pre = dp[i-1][j-1];
		    int l = dp[i][j-1];
		    int u = dp[i-1][j];
		    dp[i][j] = min(l,u);
		    dp[i][j] = min(dp[i][j],pre) + 1;
		}
		if (dp[i][j]*dp[i][j] > ans) ans = dp[i][j]*dp[i][j];
	    }
	}
	return ans;
    }
};
