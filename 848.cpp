class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int s = 0;
	string ans = S;
        for (int i = shifts.size()-1; i>=0; --i) {
	    s = (s + shifts[i])%26;
	    if (i >= ans.size()) continue;
	    ans[i] = (ans[i] - 'a' + s)%26 + 'a';
	}
	return ans;
    }
};
