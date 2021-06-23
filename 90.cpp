class Solution {
public:
    void dfs(vector<int> & buf, int cur, vector<int>& nums) {
        int i = cur;
	if (cur >= nums.size()) return;
	while(i < nums.size() && nums[i] == nums[cur]) i ++;
	if (i <  nums.size()) dfs(buf, i, nums);

	buf.push_back(nums[cur]);
	ans.push_back(buf);
	dfs(buf,cur+1,nums);
	buf.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
	vector<int> buf;
	ans.push_back(buf);
	dfs(buf,0,nums);
	return ans;
    }
    vector<vector<int>> ans;
};
