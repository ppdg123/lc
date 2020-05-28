class Solution {
public:
    vector<string> printVertically(string s) {
        int i = 0;
	int j = 0;
	int m = 0;
	vector<string> terms;
	vector<string> ans;
	while (j < s.size()) {
	    while (j < s.size() && s[j] != ' ') j++;
	    string tmp = s.substr(i,j-i);
	    terms.push_back(tmp);
	    if (m < (j-i)) m = j-i;
	    j++;
	    i = j;
	}
	for (i=0;i < m; ++i) {
	    string t;
	    for (j = 0; j<terms.size(); ++j) {
	        if (i >= terms[j].size()) t.push_back(' ');
		else t.push_back(terms[j][i]);
	    }
	    while(t.back() == ' ') t.pop_back();
	    ans.push_back(t);
	}
	return ans;
    }
};
