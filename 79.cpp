class Solution {
public:
    void dfs(vector<vector<bool>>& vis,vector<vector<char>>& board, string & w, int cur, int i, int j) {
        if(ans) return;
	if (cur >= w.size()) {ans = true; return;}
	if (i < 0 || i >= hh || j < 0 || j >= ww) return;
	if (vis[i][j]) return;
	if (board[i][j] != w[cur]) return;
	vis[i][j] = true;
	dfs(vis,board,w,cur+1,i+1,j);
	dfs(vis,board,w,cur+1,i-1,j);
	dfs(vis,board,w,cur+1,i,j+1);
	dfs(vis,board,w,cur+1,i,j-1);
	vis[i][j] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        ans = false;
	vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(), false));
	hh = board.size();
	ww = board[0].size();
	for(int i = 0; i< hh; ++i) {
	    for(int j = 0; j < ww; ++j){
	        dfs(vis,board,word,0,i,j);
		if (ans) break;
	    }
	    if (ans) break;
	}
	return ans;
    }
    bool ans;
    int hh;
    int ww;
};
