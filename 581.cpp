class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while (l < (nums.size()-1) && nums[l] <= nums[l + 1]) l++;
        if (l == (nums.size() -1)) return 0;
        while (r > 1 && nums[r] >= nums[r-1]) r--;
        if (l == 0 && nums[l] > nums[l + 1]) --l;
        if (r == (nums.size() -1) && nums[r] < nums[r -1]) ++r;
        int ma = INT_MIN;
        int mi = INT_MAX;
        for (int j = 0; j < r; ++j) {
            if (ma < nums[j]) ma = nums[j];
        }
        for (int j = l +1; j < nums.size(); ++j) {
            if (mi > nums[j]) mi = nums[j];
        }
        while (l >=0 && nums[l] > mi) l --;
        while (r < nums.size() && nums[r] < ma) r++;
        return (r - l -1);
    }
};
