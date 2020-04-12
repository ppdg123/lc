class Solution {
public:
    void dfs_ok(int a, int b, vector<vector<int>>& grid, bool f) {
        if (a < 0 || a >= h || b < 0 || b >= w) return;
        if (grid[a][b] == -1) {grid[a][b] = -2; return;}
        if (grid[a][b] != 1) return;
        grid[a][b] = 2;
        if (f) {
            cnt ++;
        }
        dfs_ok(a-1,b,grid,f);
        dfs_ok(a+1,b,grid,f);
        dfs_ok(a,b-1,grid,f);
        dfs_ok(a,b+1,grid,f);
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        h = grid.size();
        w = grid[0].size();
        for (int i = 0; i<hits.size(); ++i) {
            int a = hits[i][0];
            int b = hits[i][1];
            if (a < 0 || a >= h || b < 0 || b >= w || grid[a][b] == 0) {
                continue;
            } else grid[a][b] = -1;
        }
        for (int i = 0; i< w; ++i) {
            dfs_ok(0,i,grid,false);
        }
        for(int i=hits.size()-1; i>=0 ; --i) {
            int a = hits[i][0];
            int b = hits[i][1];
            if (a < 0 || a >= h || b < 0 || b >= w) {
                cnt = 0;
            } else {
                if (grid[a][b] == -2) {
                    cnt = -1;
                    grid[a][b] = 1;
                    dfs_ok(a,b,grid,true);
                } else if (grid[a][b] == -1) {
                    grid[a][b] = 1;
                    cnt = 0;
                } else cnt = 0;
            }
            ans.push_back(cnt);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    };
    vector<int> ans;
    int h;
    int w;
    int cnt = 0;
};

