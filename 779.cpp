class Solution {
public:
    int dfs(int k) {
        if (k == 0) return 0;
	if (k == 1) return 1;
        if (dfs(k/2)) {
	    if(k%2 == 0) return 1;
	    else return 0;
	} else {
	    if(k%2 == 0) return 0;
	    else return 1;
	}
    }
    int kthGrammar(int N, int K) {
        return dfs(K-1);
    }
};

