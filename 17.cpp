class Solution {
public:
    void dfs(string buf, int cur, string digits) {
        if (cur > digits.size()) return;
	if (cur == digits.size()) {
	    ans.push_back(buf);
	    return;
	}
        for (int i = 0; i < mp[digits[cur]].size(); ++i) {
	    dfs(buf + mp[digits[cur]][i],cur+1,digits);
	}
    }
    vector<string> letterCombinations(string digits) {
	ans.clear();
        if (digits == "") return ans;
        mp['0'] = "";
	mp['1'] = "";
	mp['2'] = "abc";
	mp['3'] = "def";
	mp['4'] = "ghi";
	mp['5'] = "jkl";
	mp['6'] = "mno";
	mp['7'] = "pqrs";
	mp['8'] = "tuv";
	mp['9'] = "wxyz";
	dfs("",0,digits);
	return ans;
    }

    unordered_map<char,string> mp;
    vector<string> ans;
};
