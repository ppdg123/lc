class Solution {
public:
    void dfs(int rid,long pre, long top, char op, string num, int cur,bool flag) {
        if(cur == num.size()) {
	    if ((pre+top) == tg) {
	        rd[rid] = '\0';
	        an.push_back(string(rd));
	    }
            return;
        }
        if (flag){
	    rd[rid] = '+';
	    dfs(rid+1,pre,top,'+',num,cur,false);
	    rd[rid] = '-';
	    dfs(rid+1,pre,top,'-',num,cur,false);
	    rd[rid] = '*';
	    dfs(rid+1,pre,top,'*',num,cur,false);
        } else {
            if(num[cur] == '0') {
	        rd[rid] = '0';
	        if(op == '+') dfs(rid+1,pre+top,0,op,num,cur+1,true);
	        if(op == '-') dfs(rid+1,pre+top,0,op,num,cur+1,true);
	        if(op == '*') dfs(rid+1,pre,0,op,num,cur+1,true);
                return;
            }
	    long tmp = 0;
	    string tm;
            for (int i = cur; i<num.size(); ++i) {
                tmp = tmp * 10 + num[i] - '0';
		rd[rid] = num[i];
		if (op == '+') dfs(rid+1,pre+top,tmp,op,num,i+1,true);
		if (op == '-') dfs(rid+1,pre+top,-tmp,op,num,i+1,true);
		if (op == '*') dfs(rid+1,pre,tmp*top,op,num,i+1,true);
		rid ++;
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        tg = target;
        dfs(0,0,0,'+',num,0,false);
        return an;
    }
    vector<string> an;
    int tg;
    char rd[100];
};

