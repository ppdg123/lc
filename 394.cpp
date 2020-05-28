class Solution {
public:
    string ans;
    string dfs(string s , int& ptr) {
        string res;
        while (ptr < s.size() && s[ptr] != ']') {
	    if (s[ptr]>='0'&&s[ptr]<='9') {
	        int tm = 0;
	        while (s[ptr]>='0'&&s[ptr]<='9') {
		    tm = tm*10 + s[ptr] - '0';
		    ptr++;
		}
		ptr ++;
		string tmp = dfs(s,ptr);
		while (tm--) res += tmp;
		ptr++;
	    } else {
	        res += s[ptr];
		ptr++;
	    }
	}
	return res;
    }
    string decodeString(string s) {
        int ptr = 0;
	while (ptr < s.size()) {
	    ans += dfs(s,ptr);
	    ptr++;
	}
	return ans;
    }
};
