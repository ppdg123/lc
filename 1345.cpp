class Solution {
public:
    struct node {
        int idx;
	int val;
	int step;
    };
    int minJumps(vector<int>& arr) {
        map<int,vector<int>> buf;
	for (int i = 0; i< arr.size(); ++i) {
	    if(buf.find(arr[i]) == buf.end()) {
	        buf[arr[i]] = vector<int>(1,i);
	    } else {
	        buf[arr[i]].push_back(i);
	    }
	}
	vector<bool> vis(arr.size(),false);
	vis[0] = true;
	vector<struct node> q;
	struct node tmp;
	tmp.idx = 0;
	tmp.step = 0;
	tmp.val = arr[0];
	q.push_back(tmp);
	int i = 0;
	int target = arr.size()-1;
	int idx,step,val;
	while(i < q.size()) {
	    idx = q[i].idx;
	    step = q[i].step;
	    val = q[i].val;
	    i++;
	    if (idx == target) return step;
	    for(int j = 0; j< buf[val].size(); ++j){
	        if(!vis[buf[val][j]]) {
		    vis[buf[val][j]] = true;
		    tmp.step = step+1;
		    tmp.idx = buf[val][j];
		    q.push_back(tmp);
		}
	    }
	    buf.earse(val);
	    if((idx+1)<arr.size() && !vis[idx+1]) {
	        tmp.step = step +1;
		tmp.idx = idx+1;
		tmp.val = arr[idx+1];
		q.push_back(tmp);
		vis[idx+1] = true;
	    }
	    if((idx-1)>=0 && !vis[idx-1]) {
	        tmp.step = step +1;
		tmp.idx = idx-1;
		tmp.val = arr[idx-1];
		q.push_back(tmp);
		vis[idx-1] = true;
	    }
	}
	return -1;
    }
};

