class Solution {
public:
    map<int,double> buf;
    double pw(double x, long n) {
        if(buf.find(n) != buf.end()) return buf[n];
        if(n == 0) return 1.0;
        if(n==1) return x;
        long m = n/2;
        double tmp =  pw(x,m)*pw(x,n-m);
        buf[n] = tmp;
        return tmp;
    }
    double myPow(double x, long n) {
        if (n < 0) return 1.0/pw(x,-n);
        else return pw(x,n);
    }
};
