class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
	int end = 0;
	int maxpos = 0;
	for (int i = 0; i<nums.size(); ++i){
	    if ((i+nums[i]) > maxpos) {
	        maxpos = i + nums[i];
	    }
	    if (i == end){
	        end = maxpos;
		ans ++;
	    }
	}
	return ans;
    }
};
