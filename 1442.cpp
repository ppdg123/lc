class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),0));
	for (int i = 0; i < arr.size(); ++i) {
	    dp[i][i] = arr[i];
	    for (int j=i-1;j>=0;--j) {
	        dp[j][i] = dp[j+1][i] ^ arr[j];
	    }
	}
	int ans = 0;
	for (int i = 0; i < arr.size(); ++i) {
	    map<int,int> cnt;
	    for(int j =i; j>=0 ; --j){
	        cnt[dp[j][i]] ++;
	    }
	    for (int j = i+1; j < arr.size(); ++j) {
	        if (cnt.find(dp[i+1][j]) != cnt.end()) {
		    ans += cnt[dp[i+1][j]];
		}
	    }
	}
	return ans;
    }
};
