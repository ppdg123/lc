#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int pmax(int a, int b ) { return a>b?a:b;}
    void dfs(string seq,int cur,int l, int ml, int r,int mr) {
        if (cur >= seq.size()) {
	    if(l==0 && r==0) {
	        int tmp = pmax(ml,mr);
	        if(tmp < minv) {
	            minv = tmp;
		    ans = e;
	        }
	    }
	    return;
	}
	if (seq[cur] == '(') {
	    e[cur] = 0;
	    dfs(seq,cur+1,l+1,(l+1)>ml?(l+1):ml,r,mr);
	    e[cur] = 1;
	    dfs(seq,cur+1,l,ml,r+1,(r+1)>mr?(r+1):mr);
	} else {
	    if (l>0) {
	        e[cur] = 0;
	        dfs(seq,cur+1,l-1,ml,r,mr);
	    }
	    if (r>0) {
	        e[cur] = 1;
	        dfs(seq,cur+1,l,ml,r-1,mr);
	    }
	}
    }
    vector<int> maxDepthAfterSplit(string seq) {
        e.resize(seq.size());
	minv = 10000;
	dfs(seq,0,0,0,0,0);
	return ans;
    }
    vector<int> ans;
    vector<int> e;
    int minv;
};

int main(){
    Solution s;
    vector<int> ans = s.maxDepthAfterSplit("(()())");
    for (int i = 0; i< ans.size(); ++i) {
        printf("%d\n",ans[i]);
    }
    return 0;
}
