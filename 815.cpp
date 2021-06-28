class Solution {
public:
    struct node {int len , id;};
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        vector<set<int>> mp;
        set<int> st,en;
        st.insert(source);
        en.insert(target);
        mp.push_back(st);
        for (int i = 0; i < routes.size(); ++i) {
            set<int> tmp;
            for (int j = 0; j< routes[i].size(); ++j) {
                tmp.insert(routes[i][j]);
            }
            mp.push_back(tmp);
        }
        set<int>tmp;
        tmp.insert(target);
        mp.push_back(tmp);
        vector<vector<int>> edge(mp.size());
        for(int i = 0; i < mp.size(); ++i) {
            for(int j = i+1; j < mp.size(); ++j) {
                set<int> tmp;
                set_intersection(mp[i].begin(), mp[i].end(), mp[j].begin(), mp[j].end(), inserter(tmp,tmp.begin() ));
                if (tmp.size() > 0) {
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }
        queue<struct node> q;
        struct node nd;
        nd.id = 0;
        nd.len = 0;
        q.push(nd);
        vector<bool> vis(mp.size(), false);
        vis[0] = true;
        while(q.size() > 0) {
            int cur = q.front().id;
            int cur_len = q.front().len;
            q.pop();
            if (cur == (mp.size()-1)) return cur_len -1;
            for (int i = 0; i < edge[cur].size(); ++i) {
                if(vis[edge[cur][i]]) continue;
                struct node tmp;
                tmp.id = edge[cur][i];
                tmp.len = cur_len +1;
                vis[tmp.id] = true;
                q.push(tmp);
            }
        }
        return -1;
    }};
