class Solution {
public:
    void dfs(vector<int> & buf) {
    	if (buf.size() == n) {
	    ans.push_back(buf);
	    return;
	}
	for (int i = 0; i < keys.size(); ++i) {
	     if (mp[keys[i]]) {
	         mp[keys[i]] --;
		 buf.push_back(keys[i]);
		 dfs(buf);
		 buf.pop_back();
		 mp[keys[i]] ++;
	     }
	}
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	ans.clear();
	mp.clear();
	keys.clear();
	n = nums.size();
	for (int i = 0; i < nums.size(); ++i) {
	    if (mp.find(nums[i]) != mp.end()) {
	        mp[nums[i]] += 1;
	    } else {
	    	mp[nums[i]] = 1;
		keys.push_back(nums[i]);
	    }
	}
	vector<int> buf;
	dfs(buf);
	return ans;
    }
    vector<vector<int>> ans;
    map<int, int> mp;
    vector<int> keys;
    int n;
};
