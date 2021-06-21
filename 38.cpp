class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
	while (--n) {
	    string newstr = "";
	    int i = 0;
	    int pre = 0;
	    int cnt = 0;
	    while(i < cur.size()) {
	        if(cur[i] == cur[pre]) { ++ cnt;}
		else {
		    newstr += to_string(cnt);
		    newstr += cur[pre];
		    pre = i;
		    cnt = 1;
		}
		++i;
	    }
	    if (cnt > 0) {
		    newstr += to_string(cnt);
		    newstr += cur[pre];
	    }
	    cur = newstr;
	}
	return cur;
    }
};
