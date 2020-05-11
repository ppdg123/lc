class Solution {
public:
    double dfs(double x, int n){
        if(n == 0) return 1.0;
        if(n == 1) return x;
	if(ans.find(n) != ans.end()) return ans[n];
	int m = n/2;
	double tmp = dfs(x,m);
	if (m*2 != n) {
	    ans[n] = x*tmp*tmp;
	} else {
	    ans[n] = tmp*tmp;
	}
	return ans[n];
    }
    double myPow(double x, int n) {
        double res = dfs(x,abs(n));
	if (n >= 0) return res;
	else return 1.0/res;
    }
    map<int,double> ans;
};

