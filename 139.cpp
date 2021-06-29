class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> mp;
	for(int i = 0; i < wordDict.size(); ++i) {
	    mp.insert(wordDict[i]);
	}
	vector<int> dp(s.size() + 1, false);
	dp[0] = true;
	for (int i = 1; i <= s.size(); ++i) {
	    for (int j = 0;j < i; ++j) {
	        string tmp = s.substr(j,i-j);
		if(dp[j] && mp.find(tmp) != mp.end()) {
		    dp[i] = true;
		}
	    }
	}
	return dp.back();
    }
};
