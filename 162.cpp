class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        vector<int> numss;
	numss.push_back(INT_MIN);
	for (int i = 0; i < nums.size(); ++i) {
	    numss.push_back(nums[i]);
	}
	numss.push_back(INT_MIN);
	nums = numss;
        int l = 1;
	int r = nums.size() -2;
	int m ;
	while ((r-l) >1) {
	    m = (l + r) /2;
	    if (nums[m] > nums[m-1]) {
	        l = m;
	    } else {
	        r = m;
	    }
	}
	if (l == r) return l-1;
	if (nums[l] > num[r]) return l-1;
	else return r-1;
    }
};
