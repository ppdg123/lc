class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> pre(triangle.back().size(),0);
	vector<int> cur(triangle.back().size(),0);
	for (int i = 0; i < triangle.size(); ++i) {
	    for (int j = 0; j < triangle[i].size(); ++j) {
	       if (j == 0) {
	          cur[j] = pre[j] + triangle[i][j];
	       } else if(j == (triangle[i].size() -1)) {
	           cur[j] = pre[j - 1] + triangle[i][j];
	       }else{
	          cur[j] = (pre[j]>pre[j-1]?pre[j-1]:pre[j]) +  triangle[i][j];
	       }
	    }
	    pre = cur;
	}
	int ans = cur[0];
	for (int i = 1; i < triangle.back().size(); ++i) {
	    if (cur[i] < ans) ans = cur[i];
	}
	return ans;
    }
};

