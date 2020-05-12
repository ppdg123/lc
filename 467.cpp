class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> cnt(26,0);
	int i =0;
	int j = i;
	while(i < p.size()){
	    if(cnt[p[j] - 'a'] < (j-i+1)) {
	        cnt[p[j] - 'a'] = j - i + 1;
	    }
	    if ((j+1) < p.size() && (p[j+1]-'a') == (p[j] - 'a' + 1)%26) {
	        j++;
	    } else {
	        i = j+1;
		j = i;
	    }
	}
	int ans = 0;
	for (i = 0; i<26; ++i) ans += cnt[i];
	return ans;
    }
};
