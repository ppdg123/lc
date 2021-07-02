class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
	vector<int> dp(nums.size(),0);
	vector<int> path(nums.size(),0);
	dp[0] = 1;path[0] = 0;
	int ans = 1;
	int tail = 0;
	for (int i =1; i < nums.size(); ++i) {
	    int t = 0;path[i] = i;
	    int idx = i;
	    for (int j = 0; j < i; ++j) {
	         if (nums[i]%nums[j] == 0) {
		     if (t < dp[j]) {
		         t = dp[j];
			 idx = j;
		     }
		 }
	    }
	    path[i] = idx;
	    dp[i] = t +1;
	    if (ans < dp[i]) {
	        ans = dp[i];
		tail = i;
	    }
	}
	vector<int> buf;
	while(tail != path[tail]) {
	    buf.push_back(nums[tail]);
	    tail = path[tail];
	}
	buf.push_back(nums[tail]);
	reverse(buf.begin(),buf.end());
	return buf;
    }
};
