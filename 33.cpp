class Solution {
public:
    void bs(vector<int>& nums,int l , int r, int target) {
        if (l>r) return;
	if(l==r) {
	    if(nums[l] == target) ans = l;
	    return;
	}
	int m = (l+r)/2;
	if(nums[m] == target) {ans = m;return;}
	if (nums[l] <= nums[r]){
	    if(nums[m] < target) {
	        bs(nums,m+1,r,target);
	    } else{
	        bs(nums,l,m-1,target);
	    }
	} else {
	    if (nums[l] <= nums[m]) {
	        if (target >= nums[l] && target <= nums[m]) {
		    bs(nums,l,m-1,target);
		} else {
		    bs(nums,m+1,r,target);
		}
	    } else {
	        if (target >= nums[m] && target <= nums[r]) {
		    bs(nums,m+1,r,target);
		} else {
		    bs(nums,l,m-1,target);
		}
	    }
	}
    }
    int search(vector<int>& nums, int target) {
        bs(nums,0,nums.size()-1,target);
	return ans;
    }
    int ans = -1;
};
