class Solution {
public:
    bool reorderedPowerOf2(int N) {
        long st = 1;
	set<string> s;
	while (st<1e9) {
	    string tmp;
	    long t = st;
	    while (t) {
	        tmp.push_back('0' + t%10);
		t/=10;
	    }
	    st *= 2;
	    sort(tmp.begin(),tmp.end());
	    s.insert(tmp);
	}
	string tmp;
	while(N) {
	    tmp.push_back('0' + N%10);
	    N/=10;
	}
	sort(tmp.begin(),tmp.end());
	if(s.find(tmp) != s.end()) return true;
	else return false;
    }
};
