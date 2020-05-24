class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       if(matrix.size() == 0) return ans;
       int h = matrix.size();
       int w = matrix[0].size();
       vector<vector<bool>> vis(h,vector<bool>(w,false));
       int dir = 0;
       int cnt = 0;
       int i = 0, j= 0;
       while (cnt < w*h) {
           if (!vis[i][j]) {
               ans.push_back(matrix[i][j]);
	       vis[i][j] = true;
	       cnt+=1;
	   }
	   if (dir == 0) {
	       if ((j+1)<w && !vis[i][j+1]) j++;
	       else dir = (dir+1)%4;
	   }
	   if (dir == 1) {
	       if ((i+1)<h && !vis[i+1][j]) i++;
	       else dir = (dir+1)%4;
	   }
	   if (dir == 2) {
	       if ((j-1)>=0 && !vis[i][j-1]) j--;
	       else dir = (dir+1)%4;
	   }
	   if (dir == 3) {
	       if ((i-1)>=0 && !vis[i-1][j]) i--;
	       else dir = (dir+1)%4;
	   }
       }
       return ans;
    }
    vector<int> ans;
};
