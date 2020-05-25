class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> & rd, int cur , vector<int>& nums) {
        if (cur == nums.size()) {ans.push_back(rd);return;}
	rd.push_back(nums[cur]);
	dfs(rd,cur+1,nums);
	rd.pop_back();
	dfs(rd,cur+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> rd;
        dfs(rd,0,nums);
	return ans;
    }
};
