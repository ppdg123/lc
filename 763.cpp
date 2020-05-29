class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<vector<int>> buf(26,vector<int>(2,-1));
        for (int i = 0; i<S.size(); ++i) {
            int id = S[i] - 'a';
            if (buf[id][0] == -1) buf[id][0] = i;
            buf[id][1] = i;
        }
        sort(buf.begin(),buf.end());
        int l = -1, r = -1;
        vector<int> ans;
        int i = 0;
        while(i < buf.size() && buf[i][0] < 0) i++;
        while (i<buf.size()) {
            if (l < 0) {
                l = buf[i][0];
                r = buf[i][1];
                i++;
                continue;
            }
            if (buf[i][0] <= r) {
                r = max(r,buf[i][1]);
                i++;
            } else {
                ans.push_back(r-l+1);
                l = -1;
                r = -1;
            }
        }
        if (l >=0 ) ans.push_back(r-l+1);
        return ans;
    }
};
