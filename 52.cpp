class Solution {
public:
    void dfs(int cur, int n) {
        if (cur == n) {
	    ans ++;
            return;
        }
        for (int i = 0; i < n ; ++i) {
            if(!w[i]&&!lu[i+cur]&&!ru[n-i-1+cur]) {
                w[i] = true;
                lu[i+cur] = true;
                ru[n-i-1+cur] = true;
                dfs(cur+1,n);
                w[i] = false;
                lu[i+cur] = false;
                ru[n-i-1+cur] = false;
            }
        }
    }
    int totalNQueens(int n) {
        w.resize(n,false);
        lu.resize(2*n-1,false);
        ru.resize(2*n-1,false);
	ans = 0;
        dfs(0,n);
        return ans;
    }
    vector<bool> w;
    vector<bool> lu;
    vector<bool> ru;
    int ans;
};
