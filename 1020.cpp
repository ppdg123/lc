class Solution {
public:
    void dfs(vector<vector<int>>& A, int i , int j) {
        A[i][j] = 0;
	if ((i-1)>=0 && A[i-1][j] == 1) dfs(A,i-1,j);
	if ((j-1)>=0 && A[i][j-1] == 1) dfs(A,i,j-1);
	if ((i+1) < A.size() && A[i+1][j] == 1) dfs(A,i+1,j);
	if ((j+1) < A[0].size() && A[i][j+1] == 1) dfs(A,i,j+1);
    }
    int numEnclaves(vector<vector<int>>& A) {
        if(A.size()==0) return 0;
	for (int i = 0; i<A.size(); ++i){
	     if (A[i][0] == 1) dfs(A,i,0);
	     if (A[i][A[0].size()-1]) dfs(A,i,A[0].size()-1);
	}
	for (int j = 0; j<A[0].size(); ++j) {
	    if (A[0][j] == 1) dfs(A,0,j);
	    if (A[A.size()-1][j] == 1) dfs(A,A.size()-1,j);
	}
	int ans = 0;
	for (int i = 0; i < A.size(); ++i)
	    for(int j = 0; j < A[0].size(); ++j)
	        ans += A[i][j];
	return ans;
    }
};
