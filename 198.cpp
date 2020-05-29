class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==0) return 0;
        vector<vector<int>> dp(2,vector<int>(nums.size(),0));
	dp[1][0] = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
	    dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
	    dp[1][i] = dp[0][i-1] + nums[i];
	}
	return max(dp[0][nums.size()-1],dp[1][nums.size()-1]);
    }
};
