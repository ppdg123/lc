#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    void gen(vector<int>buf,vector<int>&nums) {
        if (ans) return;
        if (buf.size() == 4) {
	    vector<double> buf1;
	    dfs(buf1,0,buf);
	    return;
	}
	for(int i = 0; i < 4; ++i) {
	    if(!vis[i]) {
	        buf.push_back(nums[i]);
		vis[i] = true;
		gen(buf,nums);
		vis[i] = false;
		buf.pop_back();
	    }
	}
    }
    void dfs(vector<double> buf, int ptr, vector<int>& nums) {
        if (ans) return;
        if(buf.size() == 1 && ptr == nums.size()) {
	    if(fabs(buf[0]-24.0) < 1e-9)  ans = true;
	    return;
	}
	if (buf.size() > 1) {
	    vector<double> tmp = buf;
	    double r = tmp.back(); tmp.pop_back();
	    double l = tmp.back(); tmp.pop_back();
	    tmp.push_back(r+l);
	    dfs(tmp,ptr,nums);
	    tmp[tmp.size()-1] = (l-r);
	    dfs(tmp,ptr,nums);
	    tmp[tmp.size()-1] = (l*r);
	    dfs(tmp,ptr,nums);
	    if (fabs(r) > 1e-9) {
	        tmp[tmp.size()-1] = (l/r);
	        dfs(tmp,ptr,nums);
	    }
	}
	if (ptr < nums.size()) {
	    vector<double> tmp = buf;
	    tmp.push_back(double(nums[ptr]));
	    dfs(tmp,ptr+1,nums);
	}
    }
    bool judgePoint24(vector<int>& nums) {
        ans = false;
	memset(vis,0,sizeof(vis));
	vector<int> buf;
	gen(buf,nums);
	return ans;
    }
    bool ans;
    bool vis[4];
};
int main(){
    vector<int> buf;
    buf.push_back(4);
    buf.push_back(1);
    buf.push_back(8);
    buf.push_back(7);
    Solution s;
    cout<<s.judgePoint24(buf)<<endl;
return 0;
}
