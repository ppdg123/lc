class Solution {
public:
    struct node {string s; int cnt;};
    int openLock(vector<string>& deadends, string target) {
        memset(vis,0,sizeof(vis));
	queue<struct node> q;
	struct node nd;
	nd.s = "0000";
	nd.cnt = 0;
	q.push(nd);
	for (int i = 0; i < deadends.size(); ++i) {
	   vis[stoi(deadends[i])] = true;
	}
	if (vis[0]) return -1;
	vis[0] = true;
	while(q.size() > 0) {
	    string tmp = q.front().s;
	    int cnt = q.front().cnt;
	    if (tmp == target) return cnt;
	    q.pop();
	    for(int i = 0; i < 4; ++i) {
	        int cur = tmp[i] - '0';
		string t = tmp;
		int c = (cur + 1)%10;
		t[i] = '0' + c;
		int key = stoi(t);
		if (!vis[key]) {
		    vis[key] = true;
		    struct node tn;
		    tn.s = t;
		    tn.cnt = cnt +1;
		    q.push(tn);
		}
		t = tmp;
		c = cur -1;
		if (c < 0) c = 9;
		t[i] = '0' + c;
		key = stoi(t);
		if (!vis[key]) {
		    vis[key] = true;
		    struct node tn;
		    tn.s = t;
		    tn.cnt = cnt +1;
		    q.push(tn);
		}
	    }
	}
	return -1;
    }
    bool vis[10000];
};
