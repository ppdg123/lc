class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> buf(1,0);
	if (n == 0) return buf;
	vector<int> nxt;
	int cnt = 1;
	buf.push_back(1);
	for (int i = 1; i<n; ++i) {
	    nxt = buf;
	    cnt = cnt << 1;
	    for (int j = buf.size()-1; j>=0 ; --j) {
	        nxt.push_back(buf[j] | cnt);
	    }
	    buf = nxt;
	}
	return buf;
    }
};
