class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long> q;
	long s = 0;
	for (int i = 0; i < target.size(); ++i) {
	    s += target[i];
	    q.push(target[i]);
	}
	bool ans = true;
	while(q.top() != 1) {
	    long v = q.top();
	    q.pop();
	    long df = s-v;
	    long tm;
	    if (df == 0){
	        if(s!=1) return false;
		return true;
	    }
	    else {tm = (v-q.top())/df; if (tm<1) tm = 1;}
	    long nxt = v-df*tm;
	    s = s - df*tm;
	    q.push(nxt);
	    if (nxt < 1) {ans = false; break;}
	}
	return ans;
    }
};
