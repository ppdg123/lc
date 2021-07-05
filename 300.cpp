class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int ans = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int cnt = 0;
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j] && cnt < dp[j]) cnt = dp[j];
            }
            dp[i] = cnt+1;
            if (ans < dp[i]) ans = dp[i];
        }
        return ans;
    }
};
