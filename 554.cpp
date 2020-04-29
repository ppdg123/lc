class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int h = wall.size();
	int m = 0;
	for (int i = 0; i<h; ++i) {
	    int st = 0;
	    for (int j = 0; j < (wall[i].size() - 1); j++) {
	        st += wall[i][j];
		if(cnt.find(st) == cnt.end())
		    cnt[st] = 0;
		cnt[st] += 1;
		if (m < cnt[st]) m = cnt[st];
	    }
	}
	return h-m;
    }
    int ans;
    map<int,int> cnt;
    map<int,int>::iterator cnt_it;
};

