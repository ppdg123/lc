#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
	int i,j;
	bool vis[1001][1001];
	memset(vis,0,sizeof(vis));
	if (s == "") return "";
	ans = s.substr(0,1);
	for (i = 0; i< s.size(); i++) vis[i][i] = true;
	for (i = 0; i< s.size(); i++) {
	    for(j = i; j >=0 ; j--) {
	        if (s[i] == s[j]) {
		    if ((i - j) > 1) {
		        vis[j][i] = vis[j+1][i-1];
		    } else vis[j][i] = true;
		}else vis[j][i] = false;
		if (vis[j][i] && (i - j + 1) > ans.size()) {
		    ans = s.substr(j,i-j+1);
		}
	    }
	}
        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.longestPalindrome("babad")<<endl;
    return 0;
}
