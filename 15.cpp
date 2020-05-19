class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int i =0;
       while(i < nums.size()) {
           int j = i+1;
           int k = nums.size()-1;
           while(j<k) {
               int s = nums[j] + nums[i] + nums[k];
               if (s < 0) {
                   int tmp = nums[j];
                   while(j<k&&nums[j] == tmp) j++;
               } else if (s>0){
                   int tmp = nums[k];
                   while(j<k&&nums[k] == tmp) k--;
               } else {
                   vector<int> t;
                   t.push_back(nums[i]);
                   t.push_back(nums[j]);
                   t.push_back(nums[k]);
                   ans.push_back(t);
                   int tmp = nums[j];
                   while(j<k&&nums[j] == tmp) j++;
               }
           }
	   int tmp = nums[i];
	   while(i<nums.size() && nums[i] == tmp) i++;
       }
       return ans;
    }
};
