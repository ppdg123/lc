class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push_back(x);
	h.push_back(x);
	int cur = s.size()-1;
	while(cur > 0 && h[cur/2] > h[cur]) {
	    int tmp = h[cur/2];
	    h[cur/2] = h[cur];
	    h[cur] = tmp;
	    cur = cur /2;
	}
    }
    
    void pop() {
       int val = s.back();
       int i;
       for (i = 0; i<h.size(); ++i){
           if (h[i] == val) break;
       }
       h[i] = h.back();
       int j = i;
       h.pop_back();
       while(j < h.size()){
       i=j;
       while(i > 0 && h[i/2] > h[i]) {
	    int tmp = h[i/2];
	    h[i/2] = h[i];
	    h[i] = tmp;
	    i = i /2;
       }
       j++;
       }
       s.pop_back();
    }
    int top() {
        return s.back();
    }
    
    int getMin() {
        return h[0];
    }
    vector<int> h;
    vector<int> s;
};
