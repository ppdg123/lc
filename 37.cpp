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
    void dfs(vector<vector<char>>& board,int cur) {
        if (cur >= dfsn.size()) ans = true;
        if (ans) return;
        int a = dfsn[cur].a;
        int b = dfsn[cur].b;
        int sq = (a/3)*3+b/3;
        for (int i=0; i< dfsn[cur].cand.size(); ++i) {
            int tmp = dfsn[cur].cand[i];
            if (rvis[a][tmp] == 0 && cvis[b][tmp] == 0 && svis[sq][tmp] == 0) {
                rvis[a][tmp] = 1;
                cvis[b][tmp] = 1;
                svis[sq][tmp] = 1;
                board[a][b] = '1' + tmp;
                dfs(board,cur+1);
                rvis[a][tmp] = 0;
                cvis[b][tmp] = 0;
                svis[sq][tmp] = 0;
                board[a][b] = '.';
            }
        }
    }

    void rnum(int a , int b, struct node & res) {
        int sq = (a/3)*3+b/3;
        res.a = a;
        res.b = b;
        for (int i = 0; i < 9; ++i) {
            if (rvis[a][i] == 0 && cvis[b][i] == 0 && svis[sq][i] == 0) {
                res.cand.push_back(i);
            }
        }
    }
    static bool cmp(struct node a, struct node b) {
        return a.cand.size() < b.cand.size();
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(rvis,0,sizeof(rvis));
        memset(cvis,0,sizeof(cvis));
        memset(svis,0,sizeof(svis));
        dfsn.clear();
        ans = false;
        for (int i = 0 ; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.'){
                    continue;
                }
                int tmp = board[i][j] - '1';
                rvis[i][tmp] = 1;
                cvis[j][tmp] = 1;
                svis[(i/3)*3+j/3][tmp] = 1;
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
    int rvis[9][9];
    int cvis[9][9];
    int svis[9][9];
    vector<struct node> dfsn;
    bool ans = false;
};

int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
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