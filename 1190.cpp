class Solution {
public:
    string reverseParentheses(string s) {
        string buf;
	for(int i = 0; i<s.size(); ++i) {
	    if (s[i] != ')'){
	        buf.push_back(s[i]);
	    } else {
	        while(buf.back() != '('){
		    string tmp;
		    tmp.push_back(buf.back());
		    buf.pop_back();
		}
		buf.pop_back();
		buf += tmp;
	    }
	}
	return ans;
    }
};

