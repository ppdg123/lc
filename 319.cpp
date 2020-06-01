class Solution {
public:
    int bulbSwitch(int n) {
        int k = 0;
	int ans = 0;
	int st = 3;
	while (k < n) {
	    k += st;
	    st +=2;
	    ans ++;
	}
	return ans;
    }
};
