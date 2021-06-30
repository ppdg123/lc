class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
	for (int i = 1; i <= n; ++i) {
	    int s = int(sqrt(i));
	    if (s*s == i) dp[i] = 1;
	    else {
	        int m = INT_MAX;
	        for(j = 1; j <= s; ++j) {
		    if(m > dp[i - j*j]) {
		        m = dp[i - j*j];
		    }
		}
		dp[i] = m +1;
	    }
	}
	return dp.back();
    }
};
