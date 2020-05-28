class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int ans = 0;
	int i = 0;
	int j = 0;
	vector<int> cnt;
	while(i<A.size()) {
	    j = 0;
	    while(i < A.size() && A[i] == 0) {j++;i++;}
	    cnt.push_back(j);
	    i++;
	}
	if (A.back() == 1) cnt.push_back(0);
	i = 0;
	j = i+S;
	while(j < cnt.size()) {
	    if (i == j) ans += (1+cnt[i])*cnt[i]/2;
	    else ans += (1+cnt[i])*(1+cnt[j]);
	    i++;j++;
	}
	return ans;
    }
};
