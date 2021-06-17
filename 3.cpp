#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
	int start = 0;
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < s.size(); ++i) {
	    if (mp.find(s[i]) != mp.end()) {
	        int tmp = mp[s[i]];
		if (tmp < start) {
		   cnt ++;
		} else {
		    start = mp[s[i]];
		    cnt = i - start;
		}
	    } else {
	        ++ cnt;
	    }
	    if (cnt > ans) ans = cnt;
	    mp[s[i]] = i;
	}
	return ans;
    }
};

int main(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("pwwkew")<<endl;
    return 0;
}
