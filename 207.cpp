class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> mp(numCourses);
	vector<int> out(numCourses,0);
	for (int i = 0; i < prerequisites.size(); ++i) {
	    mp[prerequisites[i][1]].insert(prerequisites[i][0]);
	    out[prerequisites[i][0]] ++;
	}
	vector<int> buf;
	for(int i = 0; i < numCourses; ++i) {
	    if (out[i] == 0) {
	        buf.push_back(i);
	    }
	}
	int cnt = 0;
	while(buf.size() > 0) {
	    int cur = buf.back();
	    buf.pop_back();
	    cnt ++;
	    for (auto &t : mp[cur]) {
	        out[t] --;
		if (out[t] == 0) {
		    buf.push_back(t);
		}
	    }
	}
	return (cnt == numCourses);
    }
};
