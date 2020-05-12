class Solution {
public:
    vector<vector<int>> ans;
    struct node {
        int val;
        int cnt;
    };
    int bs(int l, int r, int v) {
        if (l > r) return -1;
        int m = (l + r)/2;
        if (nm[m].val == v) return m;
        if (nm[m].val < v) return bs(m+1,r,v);
        if (nm[m].val > v) return bs(l,m-1,v);
        return -1;
    }
    void dfs(vector<int>rd, int s, int remain, int cur ,int target){
         if (remain == 0) {
             if (s == target) {
                 ans.push_back(rd);
             }
             return;
         }
         if (cur >= nm.size()) return;
         if ((s + remain * nm[cur].val) > target) return;
         if ((s + remain * nm.back().val) < target) return;
         if (remain == 1) {
             int v = target - s;
             int idx = bs(cur,nm.size()-1,v);
             if (idx > 0) {
                 rd.push_back(nm[idx].val);
                 ans.push_back(rd);
                 rd.pop_back();
             }
             return;
         }
         for (int i = 0; i <= nm[cur].cnt&& i <= remain; ++i) {
             int j = i;
             while(j--){
                 rd.push_back(nm[cur].val);
             }
             dfs(rd,s+nm[cur].val*i,remain-i,cur+1,target);
             j = i;
             while(j--) {
                 rd.pop_back();
             }
         }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i = 0;
        while(i < nums.size()) {
            int cnt = 1;
            while(i < (nums.size()-1) && nums[i] == nums[i+1]){
                i++;
                cnt ++;
            }
            struct node tmp;
            tmp.val = nums[i];
            tmp.cnt = cnt;
            nm.push_back(tmp);
            i++;
        }
        vector<int> rd;
        dfs(rd,0,4,0,target);
        return ans;
    }
    vector<struct node> nm;
};
