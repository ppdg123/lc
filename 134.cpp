class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> df(gas.size(),0);
	for(int i = 0; i < gas.size(); ++i) {
	    df[i] = gas[i] - cost[i];
	}
	int n = gas.size();
	int i = 0;
	while(i < n) {
	    int tmp = 0;
	    int cnt = 0;
	    while(cnt < n) {
	        if ((tmp + df[(i+cnt)%n]) < 0) {
		     break;
		} else {
		     tmp += df[(i+cnt)%n];
		     ++ cnt;
		}
	    }
	    if (cnt == n) return i;
	    else {i += (cnt +1);}
	}
	return -1;
    }
};
