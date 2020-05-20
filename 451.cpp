struct node {char ch; int cnt;};
bool operator < (struct node a, struct node b) {
    return a.cnt > b.cnt;
}

class Solution {
public:
    string frequencySort(string s) {
        map<char,int> vis;
	for (int i = 0 ; i < s.size(); ++i) {
	    if (vis.find(s[i]) != vis.end()) {
	        vis[s[i]] ++;
	    } else {
	        vis[s[i]] = 1;
	    }
	}
        map<char,int>::iterator it;
	vector<struct node> buf;
	for (it = vis.begin(); it != vis.end(); ++it) {
	    struct node tmp;
	    tmp.ch = it->first;
	    tmp.cnt = it->second;
	    buf.push_back(tmp);
	}
	sort(buf.begin(),buf.end());
	string ans;
	for (int i = 0; i < buf.size(); ++i) {
	    for (int j = 0; j < buf[i].cnt; ++j){
	        ans += buf[i].ch;
	    }
	}
	return ans;
    }
};
