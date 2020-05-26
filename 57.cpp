class Solution {
public:
    vector<int> cross(vector<int> a,vector<int> b) {
        vector<int> ans;
	int l = max(a[0],b[0]);
	int r = min(a[1],b[1]);
	if (l > r) return ans;
	ans.push_back(min(a[0],b[0]));
	ans.push_back(max(a[1],b[1]));
	return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        vector<vector<int>> anss;
	bool f = false,ff=false;
	for (int i = 0; i < intervals.size(); ++i) {
	    vector<int> tmp = cross(intervals[i],newInterval);
	    if (tmp.size() == 0) {
	        if (f) {
		    f = false;
		    ff = true;
		    ans.push_back(newInterval);
		}
	        ans.push_back(intervals[i]);
	    } else {
	        f = true;
		newInterval = tmp;
	    }
	}
        for(int i = 0; i<ans.size(); ++i) {
          if (ans[i][0]>newInterval[1] && !ff) {
	     anss.push_back(newInterval);
	     anss.push_back(ans[i]);
	     ff = true;
	 } else anss.push_back(ans[i]);
     }
     if (!ff) anss.push_back(newInterval);
     return anss;
    }
};

