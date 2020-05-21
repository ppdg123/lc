class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        long n = num;
	long id = 1;
	while ((num&id) == 0) id = id << 1;
	long lid = id;
	long ln = n;
	long base = 0;
	while (lid&ln) {
	    ln = ln ^ lid;
	    base = ((base << 1) | 1);
	    lid = lid << 1;
	}
	ln = (ln | lid) | (base>>1);
	if (ln > INT_MAX) ln = -1;
	long rid = 1;
	long rn = n;
	base = 0;
	while ((rn&rid) > 0) {
	    rn = rn ^ rid;
	    base = (base<<1) | 1;
	    rid = rid << 1;
	}
	while(rid<n && (rid&rn) == 0) {
	    rid = rid << 1;
	    base = base << 1;
	}
	if (rid > n) rn = -1;
	else {
	    rn = (rn^rid) | (rid >>1) | (base >> 1);
	}
	vector<int> ans;
	ans.push_back(ln);
	ans.push_back(rn);
	return ans;
    }
};
