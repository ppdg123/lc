class Solution {
public:
    int magicalString(int n) {
        vector<int> buf;
	buf.push_back(1);
	buf.push_back(2);
	buf.push_back(2);
	int i = 2;
	int cur = 1;
	int ans = 0;
	while (buf.size() < n) {
	    if (buf[i] == 2) {
	        buf.push_back(cur);
	        buf.push_back(cur);
	    } else {
	        buf.push_back(cur);
	    }
	    if (cur == 1) cur = 2;
	    else cur = 1;
	    i++;
	}
	for (int i = 0 ; i<n ; ++i)
	    if(buf[i] == 1) ans ++;
	return ans;
    }
};
