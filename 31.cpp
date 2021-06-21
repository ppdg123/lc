class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
	int j,t = 999,x,y;
	bool f = false;
	while(i >= 0) {
	    for(j = i+1; j < nums.size(); ++j) {
	        if (nums[i] < nums[j] && nums[j] < t) {
		    t = nums[j];
		    f = true;
		    y = j;
		}
	    }
	    if (f) {
	        x = nums[i];
		nums[i] = nums[y];
		nums[y] = x;
		sort(nums.begin()+i+1,nums.end());
		break;
	    }
	    -- i;
	}
	if (f) return;
	sort(nums.begin(),nums.end());
    }
};
