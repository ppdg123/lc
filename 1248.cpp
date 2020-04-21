class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int lb = -1,rb = -1,l=0,r=0,cnt = 0;
        while (l < nums.size() && nums[l]%2==0) l ++;
        r = l;
        cnt = 1;
        int ans = 0;
        while (r < nums.size()) {
            if (cnt < k) {
                 r ++;
                 if (r < nums.size() && nums[r]%2 == 1) cnt ++;
                 continue;
            }
            if (cnt == k) {
                rb = r +1;
                while (rb < nums.size() && nums[rb]%2 == 0) rb ++;
                ans += (rb-r) * (l-lb);
                r = rb;
                lb = l;
                l ++;
                while(l < nums.size() && nums[l]%2==0) l++;
            }
        }
        return ans;
    }
};
