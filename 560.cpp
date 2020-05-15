class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,vector<int>> vis;
	vis[0] = vector<int>(1,0);
	int sum = 0;
	int ans;
	for(int i = 0; i< nums.size(); ++i) {
	    sum += nums[i];
	    if(vis.find(sum-k) != vis.end()) {
	        ans += vis[sum-k].size();
	    }
	    if (vis.find(sum) != vis.end()) {
	        vis[sum].push_back(i);
	    } else {
	        vis[sum] = vector<int>(1,i);
	    }
	}
	return ans;
    }
};
