class Solution {
public:
    int myAtoi(string str) {
       long long tmp=0,f=0;
       bool hit = false;
       for (int i = 0; i < str.size(); ++i) {
           if (str[i] != ' ') {
	       hit = true;
	   }
	   if (hit && !(str[i]>='0' && str[i]<='9') && str[i] != '+' && str[i] != '-') {
	       break;
	   }
	   if (hit){
	       if (str[i] == '+' || str[i] == '-') {
	           if(f == 0) {
	               if(str[i] == '-') f= -1;
		       else f = 1;
	           } else break;
		   continue;
	       }
	       if (str[i] >= '0' && str[i] <= '9') {
	           if (!f) f = 1;
	           tmp = tmp*10 + str[i] - '0';
	           if (tmp*(f?f:1) > INT_MAX) return INT_MAX;
	           if (tmp*(f?f:1) < INT_MIN) return INT_MIN;
	       }
	   }
       }
       return (int)(tmp*(f?f:1));
    }
};
