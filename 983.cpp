class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> cnt(366,0);
	int j = 0;
	int step[] = {1,7,30};
	for(int i = 1; i<cnt.size(); ++i){
	    if (j < days.size() && i==days[j]) {
		int minv = INT_MAX;
	        for(int k = 0; k < costs.size(); ++k){
		    int idx = i - step[k];
		    if (idx < 0) idx = 0;
		    int tmp = cnt[idx] + costs[k];
		    if (tmp < minv) minv = tmp;
		}
		cnt[i] = minv;
	    } else {
	        cnt[i] = cnt[i-1];
	    }
	    j++;
	}
	return cnt.back();
    }
};
