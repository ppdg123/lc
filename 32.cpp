class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> buf;
	int ans = 0;
	for (int i = 0; i< s.size(); ++i) {
	    if (s[i] == '(') {
	        buf.push_back(-1);
	    } else {
	        if(!buf.empty() && buf.back() > 0) {
		    int tmp = 0;
		    while (!buf.empty() && buf.back() >0) {
		        tmp += buf.back();
			buf.pop_back();
		    }
		    if (tmp > ans) ans = tmp;
		    buf.push_back(tmp);
		}
		int tmp = -1;
	        if(!buf.empty() && buf.back() > 0) { tmp = buf.back(); buf.pop_back();}
		if(!buf.empty() && buf.back() == -1) {
		    buf.pop_back();
		    if (tmp < 0) tmp = 2;
		    else tmp += 2;
		    while (!buf.empty() && buf.back() > 0) {tmp += buf.back(); buf.pop_back();}
		    if (tmp > ans) ans = tmp;
		    buf.push_back(tmp);
		}
	    }
	}
	return ans;
    }
};
