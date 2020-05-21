class Solution {
public:
    int pmin(int a, int b) {return a>b?b:a;}
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        vector<vector<int>> dr(h,vector<int>(w,0));
        vector<vector<int>> ul(h,vector<int>(w,0));
        for (int i = 0; i < h; ++i) {
            int cnt = 0;
            for(int j = 0; j <w; ++j) {
                if (grid[i][j]) {
                    cnt ++;
                } else {
                    cnt = 0;
                }
                ul[i][j] = cnt;
            }
        }
        for (int j = 0; j < w; ++j) {
            int cnt = 0;
            for(int i = 0; i <h; ++i) {
                if (grid[i][j]) {
                    cnt ++;
                } else {
                    cnt = 0;
                }
                ul[i][j] = pmin(ul[i][j],cnt);
                cout<<ul[i][j]<<" ";
            }
            cout<<endl;
        }
        for (int i = 0; i < h; ++i) {
            int cnt = 0;
            for(int j = w-1; j >=0; --j) {
                if (grid[i][j]) {
                    cnt ++;
                } else {
                    cnt = 0;
                }
                dr[i][j] = cnt;
            }
        }
        for (int j = 0; j < w; ++j) {
            int cnt = 0;
            for(int i = h-1; i >= 0; --i) {
                if (grid[i][j]) {
                    cnt ++;
                } else {
                    cnt = 0;
                }
                dr[i][j] = pmin(dr[i][j],cnt);
                cout<<dr[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans = 0;
        for (int i = 0; i<h ; ++i) {
            for (int j = 0; j< w; ++j) {
                if(dr[i][j] > ans) {
                    for(int k = dr[i][j]; k > ans; --k) {
                        if((i+k-1) < h && (j+k-1) < w && ul[i+k-1][j+k-1] >= k && k > ans) {
                            ans = k;
                        }
                    }
                }
            }
        }
        return ans*ans;
    }
};
