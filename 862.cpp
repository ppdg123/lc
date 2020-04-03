#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<int> B,cand;
	B.push_back(0);
	int cur = 0;
	int ans = -1;
	for (int i  = 0; i< A.size(); ++i) {
	    B.push_back(B.back() + A[i]);
	}
	for (int i = 0; i<B.size(); ++i) {
	    while(cand.size() && B[cand.back()] >= B[i]) {
	        cand.pop_back();
	    }
	    while(cur < cand.size() && (B[i]-B[cand[cur]]) >= K) {
	        if((i - cand[cur]) < ans || ans == -1) ans = i-cand[cur];
		cur ++;
	    }
	    cand.push_back(i);
	}
	return ans;
    }
};

int main(){
    Solution s;
    vector<int> a = {84,-37,32,40,95};
    cout<<s.shortestSubarray(a,167)<<endl;
    return 0;
}
