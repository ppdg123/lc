class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
	unordered_set<int> vis;
	ans = 0;
	for (int i = 0; i < nums.size(); ++i) {
	    vis.insert(nums[i]);
	}
	for (int i = 0; i < nums.size(); ++i) {
	    if(vis.find(nums[i]-1) == vis.end()) {
	        int cnt = 1;
		while(vis.find(nums[i] + cnt) != vis.end()) {
		    ++ cnt;
		}
		if (cnt > ans) ans = cnt;
	    }
	}
	return ans;
    }
    int ans;
};
