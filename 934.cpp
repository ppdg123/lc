class Solution {
public:
    struct node {int i,j,dis;};
    int shortestBridge(vector<vector<int>>& A) {
        int h = A.size();
	int w = A[0].size();
	vector<vector<bool>> vis(h,vector<bool>(w,false));
	int i,j;
	bool f = false;
	for(i = 0; i<h; ++i) {
	    for(j=0; j<w; ++j) {
	        if (A[i][j]) {f = true;break;}
	    }
	    if(f) break;
	}
	vector<struct node> buf;
	struct node tmp;
	tmp.i = i;tmp.j=j;tmp.dis=0;
	buf.push_back(tmp);
	A[i][j] = 2;
	int cur = 0;
	while(cur < buf.size()) {
	    i = buf[cur].i;
	    j = buf[cur].j;
	    if ((i-1) >=0 && A[i-1][j] == 1) {tmp.i = i-1; tmp.j = j; tmp.dis = 0; buf.push_back(tmp);A[i-1][j] = 2;}
	    if ((j-1) >=0 && A[i][j-1] == 1) {tmp.i = i; tmp.j = j-1; tmp.dis = 0; buf.push_back(tmp);A[i][j-1] = 2;}
	    if ((i+1) < h && A[i+1][j] == 1) {tmp.i = i+1; tmp.j = j; tmp.dis = 0; buf.push_back(tmp);A[i+1][j] = 2;}
	    if ((j+1) < w && A[i][j+1] == 1) {tmp.i = i; tmp.j = j+1; tmp.dis = 0; buf.push_back(tmp);A[i][j+1] = 2;}
	    cur ++;
	}
	cur = 0;
	while(cur < buf.size()) {
	    i = buf[cur].i;
	    j = buf[cur].j;
	    int dis = buf[cur].dis;
	    if ((i-1) >=0 && (A[i-1][j] == 1 || A[i-1][j] == 0)) { if(A[i-1][j] == 1){return dis;}; tmp.i = i-1; tmp.j = j; tmp.dis = dis+1; buf.push_back(tmp);A[i-1][j] = 2;}
	    if ((j-1) >=0 && (A[i][j-1] == 1 || A[i][j-1] == 0)) { if(A[i][j-1] == 1){return dis;}; tmp.i = i; tmp.j = j-1; tmp.dis = dis+1; buf.push_back(tmp);A[i][j-1] = 2;}
	    if ((i+1) < h && (A[i+1][j] == 1 || A[i+1][j] == 0)) { if(A[i+1][j] == 1){return dis;}; tmp.i = i+1; tmp.j = j; tmp.dis = dis+1; buf.push_back(tmp);A[i+1][j] = 2;}
	    if ((j+1) < w && (A[i][j+1] == 1 || A[i][j+1] == 0)) { if(A[i][j+1] == 1){return dis;}; tmp.i = i; tmp.j = j+1; tmp.dis = dis+1; buf.push_back(tmp);A[i][j+1] = 2;}
	    cur++;
	}
	return -1;
    }
};
