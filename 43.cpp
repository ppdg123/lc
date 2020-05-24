class Solution {
public:
    vector<int> mul1(vector<int>buf,int t) {
        int pre = 0,i=0,v;
	vector<int> ans;
	while (i<buf.size() || pre != 0) {
	    if (i<buf.size()) v = buf[i];
	    else v = 0;
	    int cur = t*v + pre;
	    ans.push_back(cur%10);
	    pre = cur/10;
	    i++;
	}
	return ans;
    }
    vector<int> add1(vector<int>n1, vector<int>n2) {
       int pre = 0,i=0,l,r;
       vector<int> ans;
       while(i<n1.size() || i<n2.size() || pre !=0) {
           if (i<n1.size()) l = n1[i];
	   else l = 0;
	   if (i < n2.size()) r = n2[i];
	   else r = 0;
	   pre = pre + l + r;
	   ans.push_back(pre%10);
	   pre = pre / 10;
	   i++;
       }
       return ans;
    }
    string multiply(string num1, string num2) {
        vector<int> n1;
	for (int i = num1.size()-1; i>=0; --i) {
	    n1.push_back(num1[i] - '0');
	}
	vector<int> ans;
	for (int i = num2.size()-1; i>=0; --i) {
	    if (i < (num2.size()-1)) n1.insert(n1.begin(),0);
	    vector<int> tmp = mul1(n1,num2[i]-'0');
	    ans = add1(ans,tmp);
	}
	while(ans.size() > 0 && ans.back() == 0) ans.pop_back();
	if (ans.size()==0) ans.push_back(0);
	string anss;
	for (int i = ans.size()-1; i>=0 ; --i) { anss.push_back(ans[i]+'0');}
	return anss;
    }
};
