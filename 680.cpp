class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0; 
	int j = s.size()-1;
	bool ans = true;
	bool f = false;
	while(i<j) {
	    if(s[i] != s[j]) {
	        if(!f) {
		    f = true;
		    i++;
		    continue;
		}else {
		    ans = false;
		    break;
		}
	    }
	    i++; j--;
	}
	if (ans) return true;
	i = 0;
	j = s.size()-1;
	f = false;
	ans = true;
	while(i<j) {
	    if(s[i] != s[j]) {
	        if(!f) {
		    f = true;
		    j--;
		    continue;
		}else {
		    ans = false;
		    break;
		}
	    }
	    i++; j--;
	}
	return ans;
    }
};
