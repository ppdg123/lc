class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        string ans;
	if (numerator * denominator < 0) ans = "-";
	numerator = abs(numerator); denominator = abs(denominator);
	long z = numerator/denominator;
	ans += to_string(z);
	numerator -= (z*denominator);
	if (numerator == 0) return ans;
	ans += ".";
	unordered_map<long, long> vis;
	long cnt = 0;
	vector<long> buf;
	while(1) {
	    if (vis.find(numerator) != vis.end()) {
	        long idx = vis[numerator];
		for (long i = 0; i < idx; ++i) {
		    ans += ('0' + buf[i]);
		}
		ans += '(';
		for (long i = idx; i < buf.size(); ++i) {
		    ans += ('0' + buf[i]);
		}
		ans += ')';
		return ans;
	    }
	    vis[numerator] = cnt;
	    long cur = numerator * 10 / denominator;
	    numerator = numerator * 10 - cur * denominator;
	    buf.push_back(cur);
	    if (numerator == 0) {
	        for (long i = 0; i < buf.size(); ++i) ans += ('0' + buf[i]);
		return ans;
	    }
	    ++ cnt;
	}
    }
};

