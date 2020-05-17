class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> buf(numCourses,vector<int>(0));
        vector<bool> vis(numCourses,false);
        vector<int> du(numCourses,0);
        for (int i = 0; i<prerequisites.size(); ++i) {
            buf[prerequisites[i][1]].push_back(prerequisites[i][0]);
            du[prerequisites[i][0]] ++;
        }
        int cnt = 0;
        bool f = true;
        while(f) {
            f = false;
            for(int i = 0; i<numCourses; ++i) {
                 if (!vis[i] && du[i] == 0) {
                     ans.push_back(i);
                     vis[i] = true;
                     for (int j = 0; j < buf[i].size(); ++j) du[buf[i][j]] -- ;
                     cnt ++;
                     f = true;
                 }
            }
        }
        if (cnt == numCourses) return ans;
        return vector<int>(0);
    }
};
