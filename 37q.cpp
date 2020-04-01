#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct node {
        int a, b;
        vector<int> cand;
    };
    bool check_later(int cur) {
        int a,b,sq;
        for(int i=cur+1; i < dfsn.size(); ++i) {
	    a = dfsn[i].a;
	    b = dfsn[i].b;
            sq = (a/3)*3+b/3;
	    if (rvis[a]&cvis[b]&svis[sq]) {} else {return false;}
	}
	return true;
    }
    void dfs(vector<vector<char> >& board,int cur) {
        if (cur >= dfsn.size()) ans = true;
        if (ans) return;
        int a = dfsn[cur].a;
        int b = dfsn[cur].b;
        int sq = (a/3)*3+b/3;
	int flag = rvis[a]&cvis[b]&svis[sq];
        for (int i=0; i< dfsn[cur].cand.size(); ++i) {
            int tmp = dfsn[cur].cand[i];
            if (flag&(1<<tmp)) {
                rvis[a] &= ~(1<<tmp);
                cvis[b] &= ~(1<<tmp);
                svis[sq] &= ~(1<<tmp);
                board[a][b] = '1' + tmp;
		if (check_later(cur)) {
                    dfs(board,cur+1);
		}
		if(ans) return;
                rvis[a] |= (1<<tmp);
                cvis[b] |= (1<<tmp);
                svis[sq] |= (1<<tmp);
                board[a][b] = '.';
            }
        }
    }

    void rnum(int a , int b, struct node & res) {
        int sq = (a/3)*3+b/3;
        res.a = a;
        res.b = b;
	int flag = rvis[a]&cvis[b]&svis[sq];
        for (int i = 0; i < 9; ++i) {
            if (flag&(1<<i)) {
                res.cand.push_back(i);
            }
        }
    }
    static bool cmp(struct node a, struct node b) {
        return a.cand.size() < b.cand.size();
    }
    void solveSudoku(vector<vector<char> >& board) {
        dfsn.clear();
        ans = false;
	for (int i = 0; i< 9 ; ++i) {
	    rvis[i] = 511;
	    cvis[i] = 511;
	    svis[i] = 511;
	}
        for (int i = 0 ; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.'){
                    continue;
                }
                int tmp = board[i][j] - '1';
                rvis[i] &= ~(1<<tmp);
                cvis[j] &= ~(1<<tmp);
                svis[(i/3)*3+j/3] &= ~(1<<tmp);
            }
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    struct node tmp;
                    rnum(i,j,tmp);
                    dfsn.push_back(tmp);
                }
            }
        }
        sort(dfsn.begin(),dfsn.end(),cmp);
        dfs(board,0);
    }
    int rvis[9];
    int cvis[9];
    int svis[9];
    vector<struct node> dfsn;
    bool ans = false;
};

int main(){
    vector<vector<char> > board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    class Solution a;
    a.solveSudoku(board);
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j) {
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
    return 0;
}
