class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int h = matrix.size();
	int start = 0;
	for (int i = (h-1) ; i > 0; i -= 2) {
	    for (int j = 0; j < i; ++j) {
		int tmp = matrix[h-1-j-start][start];
		matrix[h-1-j-start][start] = matrix[h-1-start][h-1-j-start];
		matrix[h-1-start][h-1-j-start] = matrix[start+j][h-1-start];
		matrix[start+j][h-1-start] = matrix[start][start+j];
		matrix[start][start+j] = tmp;
	    }
	    start ++;
	}
    }
};
