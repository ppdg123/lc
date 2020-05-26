struct node {int h, idx;};
bool operator < (struct node l , struct node r) {
    return l.h < r.h;
} 
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
	int ans = 0;
        for (int i  = 0; i<arr.size(); ++i) {
	     struct node tmp;
	     tmp.idx = i;
	     tmp.h = arr[i];
	     buf.push_back(tmp);
	}
	sort(buf.begin(), buf.end());
	vector<int> cnt(buf.size(),0);
	for (int i = 0; i < buf.size(); ++i) {
	    int j = 1;
	    int now = 0;
	    while (j <= d && (buf[i].idx+j) < buf.size()) {
	         if (buf[i].h <= arr[buf[i].idx+j]) break;
		 if ((cnt[buf[i].idx+j]+1) > now) now = cnt[buf[i].idx+j]+1;
		 ++j;
	    }
	    j = 1;
	    while (j <= d && (buf[i].idx-j) >=0) {
	         if (buf[i].h <= arr[buf[i].idx-j]) break;
		 if ((cnt[buf[i].idx-j]+1) > now) now = cnt[buf[i].idx-j]+1;
		 ++j;
	    }
	    cnt[buf[i].idx] = now;
	    if (ans < now) ans = now;
	}
	return ans;
    }
    vector<struct node> buf;
};
