class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0; 
	int r = nums.size()-1;
	int ans = INT_MAX;
	while(l <= r) {
	    int m = (l+r)/2;
	    if (nums[m] <= nums[r]) {
	        ans = nums[m] < ans ? nums[m] : ans;
		r = m -1;
	    } else {
	        ans = nums[l] < ans ? nums[l] : ans;
		l = m +1;
	    }
	}
	return ans;
    }
};
