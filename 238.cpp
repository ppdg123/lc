class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans = nums;
	int s = 1;
	for (int i = 0; i < nums.size(); ++i) {
	    ans[i] = s;
	    s = s * nums[i];
	}
	s = 1;
	for (int i = nums.size()-1; i >= 0; --i) {
	    int tmp = nums[i];
	    nums[i] = s;
	    s = s * tmp;
	}
	for (int i = 0; i<ans.size(); ++i) {
	    ans[i] *= nums[i];
	}
	return ans;
    }
};
