class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> buf(numRows);
	int i = 0;
	int j = 0;
	bool flag = false;
	while(j < s.size()) {
	    buf[i] += s[j];
	    ++j;
	    if (flag) ++i;
	    else --i;
	    if(i < 0) {
	       flag = true;
	       i += 2;
	    }
	    if (i == numRows){
	       flag = false;
	       i -=2;
	    }
	}
	string ans;
	for (i = 0; i < numRows; ++i) {
	    ans += buf[i];
	}
	return ans;
    }
};
