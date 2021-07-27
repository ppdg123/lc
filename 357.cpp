class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
	int res[10];
	res[0] = 0;
	res[1] = 10;
	int cur = 9;
	int ans = 9;
	if (n >= 10) return 0;
	for (int i = 2; i <=n; ++i) {
	    ans *= cur;
	    cur --;
	    res[i] = ans;
	    if (cur == 0) break;
	}
	ans = 0;
	for (int i = 1; i <= n; ++i) {
	    ans += res[i];
	}
	return ans;
    }
};
