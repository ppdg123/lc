class Solution {
public:
    int bs(vector<int>& nums, int l , int r, int k) {
        int target = nums[l];
        int i = l;
        int j = r;
        while(i<=j) {
            while (i<=j && nums[i] <= target) i++;
            while (i<=j && nums[j] > target) j--;
            if (i<j) {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                i++; j--;
            }
        }
        nums[l] = nums[j];
        nums[j] = target;
        if (j == (k-1)) return nums[j];
        if (j < (k-1)) return bs(nums,j+1,r,k);
        else return bs(nums,l,j-1,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return bs(nums,0,nums.size()-1,nums.size()-k+1);
    }
};

