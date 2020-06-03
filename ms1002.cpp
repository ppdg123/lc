class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> buf;
	for(int i = 0; i<strs.size(); ++i) {
	    vector<string> p;
	    string tmp = strs[i];
	    sort(tmp.begin(),tmp.end());
	    p.push_back(tmp);
	    p.push_back(strs[i]);
	    buf.push_back(p);
	}
	sort(buf.begin(),buf.end());
	int i = 0, j =0;
	vector<vector<string>> ans;
	while(j < buf.size()) {
	    vector<string> tmp;
	    while(j < buf.size() && buf[i][0] == buf[j][0]) {
	        tmp.push_back(buf[j][1]);
		j++;
	    }
	    i = j;
	    ans.push_back(tmp);
	}
	return ans;
    }
};
