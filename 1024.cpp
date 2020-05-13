bool operator < (vector<int> a , vector<int> b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(),clips.end());
        vector<int> dp(101,-1);
        dp[0] = 0;
        for (int i = 0; i<clips.size(); ++i) {
            if (dp[clips[i][0]] == -1) continue;
            for (int j = clips[i][0]+1; j <= clips[i][1]; ++j) {
                if(dp[j] < 0) dp[j] = dp[clips[i][0]] +1;
                else{
                    if(dp[j] > (dp[clips[i][0]]+1)) {
                        dp[j] = dp[clips[i][0]] +1;
                    }
                }
            }
        }
        return dp[T];
    }
};
