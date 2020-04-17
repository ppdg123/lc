class Solution {
public:
    int msort(vector<int>& nums, int l , int r) {
        if(l>=r) return 0;
        int m = (l+r)/2;
        int cnt = msort(nums,l,m) + msort(nums,m+1,r);
        vector<int> tmp;
        int ll = l, rr = m+1;
        while(ll < (m+1) || rr <= r) {
            if (ll >= (m+1) ) {
                tmp.push_back(nums[rr]); rr++; continue;
            }
            if (rr > r) {
                tmp.push_back(nums[ll]); ll++; continue;
            }
            if (nums[ll] < nums[rr]) {
                tmp.push_back(nums[ll]); ll++;
            } else {
                tmp.push_back(nums[rr]); rr++;
            }
        }
        ll = l, rr = m+1;
        int pos = 0;
        while(ll < (m+1)) {
            if (rr <= r){
                if(nums[ll] > 2*(long)(nums[rr])) {
                    pos ++; rr++;
                } else {cnt += pos; ll++;}
            } else {
                cnt += pos;ll++;
            }
        }
        for (int i = l; i <=r ; i++) {
            nums[i] = tmp[i-l];
        }
        
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return msort(nums,0,nums.size()-1);
    }
};
