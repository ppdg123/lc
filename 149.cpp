class Solution {
public:
    struct node {int a,b;double c;};
    int father(int a, vector<int> & mp) {
        if (mp[a] == -1 || mp[a] == a) return a;
	mp[a] = father(mp[a],mp);
	return mp[a];
    }
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 2) return points.size();
        n = points.size();
	vector<struct node> s;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
	    for(int j = i+1; j < n; ++j) {
	        int x = points[i][0] - points[j][0];
		int y = points[i][1] - points[j][1];
		if (y < 0) {y = -y; x = -x;}
		if (y == 0) x= abs(x);
		double c = double(x) / sqrt(double(x*x + y*y));
		struct node nd;
		nd.a = i;
		nd.b = j;
		nd.c = c;
		s.push_back(nd);
	    }
	}
	sort(s.begin(),s.end(),[](struct node a, struct node b){return a.c < b.c;});
	vector<int> bc(n);
	for (int i = 0; i < s.size(); ++i) {
	    if (i == 0 || fabs(s[i].c - s[i-1].c) > 1e-9) {
		for (int j = 0; j < n; ++j) bc[j] = j;
	    }
	    bc[s[i].b] = father(s[i].a, bc);
	    int m = 0;
	    vector<int> cnt(n,0);
	    for (int j = 0; j < n; ++j) {
	        cnt[father(bc[j])] ++;
		if (cnt[father(bc[j])] > ans) ans = cnt[father(bc[j])];
	    }
	}
	return ans;
    }
    int n;
};
