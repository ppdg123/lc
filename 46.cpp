class Solution {
public:
    void dfs(vector<int> r, vector<int>& nums){
         if (r.size() == nums.size()){
	     ans.push_back(r);
	     return;
	 }
	 for (int i =0; i< nums.size() ; ++i) {
	     if (!vis[i]) {
	         vis[i] = true;
		 r.push_back(nums[i]);
		 dfs(r,nums);
		 r.pop_back();
		 vis[i] = false;
	     }
	 }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vis.resize(nums.size(),false);
	vector<int> r;
        dfs(r,nums);
	return ans;
    }
    vector<bool> vis;
    vector<vector<int>> ans;
}
