class Solution {
public:
    struct node {int a,b,dis;};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
         h = matrix.size();
	 w = matrix[0].size();
         ans.clear();
         ans.resize(h);
	 vis.clear();
	 vis.resize(h);
	 queue<struct node> buf;
	 for (int i = 0; i < h; ++i) {
	     ans[i].resize(w,0);
	     vis[i].resize(w,0);
	     for (int j = 0; j < w; ++j) {
	         if (matrix[i][j] == 0) {
		     struct node tmp;
		     tmp.a = i;
		     tmp.b = j;
		     tmp.dis = 0;
		     vis[i][j] = 1;
		     buf.push(tmp);
		 }
	     }
	 }
	 while(buf.size() > 0) {
	     struct node tmp = buf.front();
	     int a = tmp.a,b=tmp.b,dis=tmp.dis;
	     ans [a][b] = dis;
	     if (a > 0 && !vis[a-1][b]) {
	         struct node t; t.a = a-1; t.b = b; t.dis = dis+1;
		 buf.push(t); vis[a-1][b] =1;
	     }
	     if (b > 0 && !vis[a][b-1]) {
	         struct node t; t.a = a; t.b = b-1; t.dis = dis+1;
		 buf.push(t);vis[a][b-1] =1;
	     }
	     if (a < (h-1) && !vis[a+1][b]) {
	         struct node t; t.a = a+1; t.b = b; t.dis = dis+1;
		 buf.push(t);vis[a+1][b] = 1;
	     }
	     if (b < (w-1) && !vis[a][b+1]) {
	         struct node t; t.a = a; t.b = b+1; t.dis = dis+1;
		 buf.push(t); vis[a][b+1] =1;
	     }
	     buf.pop();
	 }
	 return ans;
    }
    vector<vector<int>> ans;
    vector<vector<int>> vis;
    int w ,h;
};
