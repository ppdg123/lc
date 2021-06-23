class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < s.size(); ++i) {
	    int val = 0;
	    if (s[i] != '0') {
		val += dp[i];
	    }
	    if (i > 0) {
	       int tmp = ((s[i-1] - '0')*10 + s[i] - '0');
	       if(tmp >= 10 && tmp <= 26) {
	           val += dp[i-1]
	       }
	    }
	    dp[i+1] = val;
	}
	return dp.back();
    }
};
