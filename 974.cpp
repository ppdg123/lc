class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        map<int,int> cnt;
	int s = 0,r;
	cnt[s] = 1;
	int ans = 0;
	for(int i = 0; i<A.size(); ++i) {
	    s += A[i];
	    if (s>0) r = s%K;
	    else {
	        r = (s+(abs(s)/K+1)*K)%K;
	    }
	    if (cnt.find(r) != cnt.end()) {
	        ans += cnt[r];
		cnt[r] ++;
	    } else {
	        cnt[r] =1;
	    }
	}
	return ans;
    }
};
