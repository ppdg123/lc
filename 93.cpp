class Solution {
public:
    void dfs(string & s, string path, int cur, bool newstart, int part, int num) {
        if (part > 3) {
	    if (part > 3 && cur >= s.size()) {
	        ans.push_back(path);
	    }
	    return;
	}
	if (newstart) {
	    if (cur > 0) path += ".";
	    if (s[cur] == '0') {
	        dfs(s,path + s[cur], cur +1, true, part +1, 0);
		return;
	    }
	    if (cur < s.size()) dfs(s,path + s[cur],cur+1,false,part,s[cur] - '0');
	} else {
	    dfs(s,path,cur,true,part +1, 0);
	    if (cur < s.size()) {
	        num = num*10 + s[cur] - '0';
	        if (num >=0 && num <=255) dfs(s,path + s[cur], cur + 1, false, part, num);
	    }
	}
    }
    vector<string> restoreIpAddresses(string s) {
        dfs(s,"",0,true,0,0);
	return ans;
    }
    vector<string> ans;
};
