class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int> tr(n+1,0);
        vector<int> du(n+1,0);
        for (int i = 0; i<edges.size(); ++i) {
	    int from = edges[i][0];
	    int to = edges[i][1];
	    du[from]++;
	    du[to]++;
	    tr[to] = from;
	}
	vector<vector<int>> rd;
	rd.resize(n);
	int cur = target;
	vector<int>r (1,0);
	double ans;
	while (cur != 1 && cur > 0) {
	    if (cur != target) {
	        r.push_back(cur);
	    }
	    rd[cur] = r;
	    cur = tr[cur];
	}
	if (cur == 1) {
	    r.push_back(cur);
	} else {
	    vector<int> rr;
	    cur = 1;
	    while(cur > 0 && rd[cur].size()<1){
	        rr.push_back(cur);
		cur = tr[cur];
	    }
	    r = rd[cur];
	    r.insert(r.end(),rr.rbegin(),rr.rend());
	}
	if (r.size() > (t+1)) return 0.0;
	ans = 1.0;
	for (int i = 1; i < r.size(); ++i) {
	    if (i == (r.size()-1)) ans *= 1.0/(double)(du[r[i]]);
	    else ans *= 1.0/(double)(du[r[i]]-1);
	}
	return ans;
    }
};
