class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
	vector<vector<string>> ans;
	for (int i = 0; i<strs.size(); ++i) {
	    string tmp = strs[i];
	    sort(tmp.begin(),tmp.end());
	    if (mp.find(tmp) != mp.end()) {
	        mp[tmp].push_back(strs[i]);
	    } else mp[tmp] = vector<string>(1,strs[i]);
	}
	for (map<string,vector<string>>::iterator it = mp.begin(); it != mp.end(); ++it) {
	    vector<string> tmp;
	    for (int i = 0 ; i < (it->second).size(); ++i) {
	        tmp.push_back((it->second)[i]);
	    }
	    ans.push_back(tmp);
	}
	return ans;
    }
};
