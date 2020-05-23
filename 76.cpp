class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> st;
        map<char,queue<int>> pre;
        set<char> ok;
        for (int i = 0; i<t.size(); ++i) {
            if (st.find(t[i]) != st.end()) {
                st[t[i]] ++;
            } else st[t[i]] = 1;
        }
        int ans = INT_MAX;
        string anss;
        for (int i = 0; i< s.size(); ++i) {
            if (st.find(s[i]) != st.end()) {
                if (pre.find(s[i])!=pre.end()) {
                    pre[s[i]].push(i);
                    if (pre[s[i]].size() > st[s[i]]) {
                        pre[s[i]].pop();
                    }
                } else {
                    pre[s[i]] = queue<int>();
                    pre[s[i]].push(i);
                }
                if (pre[s[i]].size() >= st[s[i]]) {
                    ok.insert(s[i]);
                }
            }
            if (ok.size() == st.size()) {
                 int mv = INT_MAX;
                 for (map<char,queue<int>>::iterator it = pre.begin(); it != pre.end(); ++it) {
                     if (mv > (it->second).front()) mv = (it->second).front();
                 }
                 if ((i-mv) < ans) {
                     ans = i - mv;
                     anss = s.substr(mv,ans+1);
                 }
            }
        }
        return anss;
    }
};
