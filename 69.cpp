class Solution {
public:
    int mySqrt(int x) {
        double l = 0;
	double r = x;
	double m;
	while((r-l)>1e-9) {
	    m = (l+r)/2.0;
	    if (m*m > double(x)) r = m;
	    else l = m;
	}
	return int(l+1e-9);
    }
};
