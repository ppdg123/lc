class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> buf;
        ans = INT_MIN;
	int cur = 1;
	for (int i = 0; i < nums.size(); ++i) {
	    cur *= nums[i];
	    if (cur > ans) ans = cur;
	    if (cur < 0) {
	        if(buf.size() > 0) {
		    int tmp = cur / buf[0];
		    if(tmp > ans) ans = tmp;
		} else {
		    buf.push_back(cur);
		}
	    }
	    if (cur == 0) {
	        buf.pop_back();
		cur = 1;
	    }
	}
	return ans;
    }
    int ans;
};
