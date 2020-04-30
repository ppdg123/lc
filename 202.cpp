class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
	while (s.find(n) == s.end()) {
	    s.insert(n);
	    int tmp = 0;
	    while(n) {
	        tmp += (n%10)*(n%10);
		n = n/10;
	    }
	    n = tmp;
	}
	return n == 1;
    }
};
