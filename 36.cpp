class Solution {
public :
    bool isValidSudoku (vector<vector<char>> & board) {
        bool h[81];
	bool v[81];
	bool s[81];
	memset(s,0,sizeof(s));
	memset(v,0,sizeof(v));
	memset(h,0,sizeof(h));
	for (int i = 0 ; i < 9; ++i) {
	    for (int j = 0; j < 9; ++j) {
	        if (board[i][j] == '.') continue;
		int val = board[i][j] - '1';
		if (!h[i*9+val]) {
		    h[i*9+val] = true;
		} else return false;
		if (!v[j*9+val]) {
		    v[j*9+val] = true;
		} else return false;
		if (!s[((i/3)*3 + (j/3))*9 + val]) {
		    s[((i/3)*3 + (j/3))*9 + val] = true;
		} else return false;
	    }
	}
	return true;
    }
};
