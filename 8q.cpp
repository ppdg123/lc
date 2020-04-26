class Solution {
public:
    void dfs(int cur, int n) {
        if (cur == n) {
            ans.push_back(one);
            return;
        }
        for (int i = 0; i < n ; ++i) {
            if(!w[i]&&!lu[i+cur]&&!ru[n-i-1+cur]) {
                w[i] = true;
                lu[i+cur] = true;
                ru[n-i-1+cur] = true;
                string tmp = tlp;
                tmp[i] = 'Q';
                one.push_back(tmp);
                dfs(cur+1,n);
                one.pop_back();
                w[i] = false;
                lu[i+cur] = false;
                ru[n-i-1+cur] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        w.resize(n,false);
        lu.resize(2*n-1,false);
        ru.resize(2*n-1,false);
        for (int i = 0; i < n ; ++i) tlp += ".";
        dfs(0,n);
        return ans;
    }
    vector<bool> w;
    vector<bool> lu;
    vector<bool> ru;
    vector<string> one;
    vector<vector<string>> ans;
    string tlp;
};
