#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int l = 0;
	int r = 0;
	vector<int> ans;
        for (int i=0; i< seq.size(); ++i) {
	    if (seq[i] == '(') {
	        if(l<=r) {
		    l ++;
		    ans.push_back(0);
		} else {
		    r ++;
		    ans.push_back(1);
		}
	    } else {
	        if(l<=r) {
		    r --;
		    ans.push_back(1);
		} else {
		    l --;
		    ans.push_back(0);
		}
	    }
	}
	return ans;
    }
};

int main(){
    Solution s;
    vector<int> ans = s.maxDepthAfterSplit("()(())()");
    for (int i = 0; i< ans.size(); ++i) {
        printf("%d\n",ans[i]);
    }
    return 0;
}
