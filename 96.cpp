class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
	if (n == 0) return 0;
	dp[1] = 1;
	dp[0] = 1;
	for (int i = 2; i<=n; ++i) {
	    int tmp = 0;
	    for (int j = 0; j < i; ++j) {
	        tmp += dp[j] * dp[i-j-1];
	    }
	    dp[i] = tmp;
	}
	return dp[n];
    }
};
