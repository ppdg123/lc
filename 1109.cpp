class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& booking, int n) {
	int add[20001];
	int minus[20001];
	memset(add,0,sizeof(add));
	memset(minus,0,sizeof(minus));
	for (int i = 0 ; i < booking.size(); ++i) {
	    add[booking[i][0]] += booking[i][2];
	    minus[booking[i][1]] += booking[i][2];
	}
	vector<int> ans(n,0);
	int cur = 0;
	int ptr = 0;
	for (int i = 1; i <= n; ++i) {
	    cur += add[i];
	    ans[i-1] = cur;
	    cur -= minus[i];
	}
	return ans;
    }
};

