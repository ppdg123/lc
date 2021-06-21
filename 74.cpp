class Solution {
public:
    void idx2ij(int idx , int & i , int & j) {
        i = idx / w;
	j = idx - i * w;
    }
    int getval(int idx, vector<vector<int>> & matrix) {
        int i ,j;
	idx2ij(idx,i,j);
	return matrix[i][j];
    }
    bool bs(int l , int r, int target, vector<vector<int>> & matrix) {
        if (l > r) return false;
        int m = (l + r) / 2;
	int val = getval(m, matrix);
	if (val == target) return true;
	if (val > target) return bs(l,m-1, target, matrix);
	else return bs(m+1,r, target, matrix);
    }
    bool searchMatrix(vector<vector<int>> & matrix, int target) {
        h = matrix.size();
	w = matrix[0].size();
	return bs(0, h*w-1, target, matrix);
    }
    int w,h;
};
