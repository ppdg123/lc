class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int start = 0;
        int len = n-1;
        int base = 0;
        while(len > 0) {
            for (int i = 0; i < len; ++i) {
                ans[start][start+i] = base + i + 1;
                ans[start+i][n-start-1] = base + len + i + 1;
                ans[n-start-1][n-1-start-i] = base + 2*len + i +1;
                ans[n-start-1-i][start] = base + 3*len + i + 1;
            }
            base += len*4;
            len -=2;
            start ++;
        }
        if (n%2) ans[n/2][n/2] = n*n;
        return ans;
    }
};

