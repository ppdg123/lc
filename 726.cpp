class Solution {
public:
    struct node {
        string id;
	int val;
	int op;
    };
    string countOfAtoms(string formula) {
        vector<struct node> buf;
	int cur = 0;
	while (cur < formula.size()) {
	    struct node nd;
	    nd.op = 0;
	    if (formula[cur] == '(') {
	       nd.op = 1;
	       ++cur;
	       buf.push_back(nd);
	       continue;
	    } else if (formula[cur] == ')') {
	       ++cur;
	       int tm = 1;
	       if (cur < formula.size() && formula[cur] >= '0' && formula[cur] <= '9') {
	           tm = 0;
		   while (cur < formula.size() && formula[cur] >= '0' && formula[cur] <= '9') {
		       tm = tm * 10 + formula[cur] - '0';
		       ++cur;
		   }
	       }
	       vector<struct node> tbuf;
	       while(buf.size() > 0) {
	           struct node t = buf.back();
		   buf.pop_back();
		   if (t.op == 1) break;
		   t.val *= tm;
		   tbuf.push_back(t);
	       }
	       while(tbuf.size() > 0) {
	           buf.push_back(tbuf.back());
		   tbuf.pop_back();
	       }
	    } else {
	       string id;
	       id += formula[cur];
	       ++cur;
	       while(cur < formula.size() && formula[cur] >= 'a' && formula[cur] <= 'z') {
	           id += formula[cur];
		   ++cur;
	       }
	       int cnt = 1;
	       if (cur < formula.size() && formula[cur] >= '0' && formula[cur] <= '9') {
	           cnt = 0;
		   while (cur < formula.size() && formula[cur] >= '0' && formula[cur] <= '9') {
		       cnt = cnt * 10 + (formula[cur] - '0');
		       ++cur;
		   }
	       }
	       nd.id = id;
	       nd.val = cnt;
	       buf.push_back(nd);
	    } 
	}
	map<string,int> mp;
	for (auto & tmp : buf) {
	    if (mp.find(tmp.id) != mp.end()) {
	         mp[tmp.id] += tmp.val;
	    } else {
	         mp[tmp.id] = tmp.val;
	    }
	}
	buf.clear();
	for (auto & tmp : mp) {
	    struct node nd;
	    nd.id = tmp.first;
	    nd.val = tmp.second;
	    buf.push_back(nd);
	}
	sort(buf.begin(),buf.end(),[](struct node a, struct node b){ return a.id < b.id;});
	string ans;
	for (auto & tmp : buf) {
	    ans += tmp.id;
	    if (tmp.val > 1) {
	        ans += to_string(tmp.val);
	    }
	}
	return ans;
    }
};
