#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> cnt = board;
	for (int i = 0; i< board.size(); ++i) {
	    for(int j = 0; j < board[i].size(); ++j) {
	        int tmp  = 0;
	        for(int a = -1; a <=1; ++a) {
		    for(int b = -1; b <= 1; ++b) {
		        if((i+a)>=0 && (i+a) < board.size() && (j+b)>=0 && (j+b)< board[i].size() && !(a==0 && b==0)) {
			    tmp += board[i+a][j+b];
			}
		    }
		}
		int stat = 0;
		if (tmp == 3) stat = 1;
		else if(tmp == 2) stat = board[i][j];
		cnt[i][j] = stat;
	    }
	}
	board = cnt;
    }
};

int main(){

    return 0;
}
