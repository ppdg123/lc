class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = 0;
	int bound = nums[0];
	for (int i = 1; i < nums.size() && i <= bound; ++i) {
	    if ((i+nums[i]) > bound) bound = i + nums[i];
	    if (bound >= (nums.size() - 1)) return true;
	}
	if (bound >= (nums.size() - 1)) return true;
	return false;
    }
};
