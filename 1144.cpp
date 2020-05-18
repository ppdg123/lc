class Solution {
public:
    int pmin(int a , int b) {return a>b?b:a;}
    int movesToMakeZigzag(vector<int>& nums) {
        int a = 0;
	int b = 0;
	for (int i = 0; i < nums.size(); ++i) {
	    int l = INT_MAX;
	    int r = INT_MAX;
            if ((i-1)>=0) {
	        l = nums[i-1];
	    }
	    if ((i+1) < nums.size()) {
		r = nums[i+1];
	    }
	    int m = pmin(l,r);
	    if (i%2) {
	        if (m <= nums[i]) {
		    a += (nums[i]-m+1);
		}
	    } else {
	        if (m <= nums[i]) {
		    b += (nums[i]-m+1);
		}
	    }
	}
	return pmin(a,b);
    }
};
