class Solution {
public:
    int waysToChange(int n) {
        int coin[4] = {1,5,10,25};
	vector<int> ans(1000001,0);
	ans[0] = 1;
	for (int i=0; i< 4; ++i) {
	    ans[coin[i]] ++;
	    for (int j = (coin[i]+1);j <=n;j++) {
	        ans[j] += ans[j - coin[i]];
		ans[j] = ans[j]%1000000007;
	    }
	}
	return ans[n];
    }
};
