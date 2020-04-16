class Solution {
public:
    struct node {int l , r;};
    bool cmp(struct node a, struct node b){ return a.l<b.l;}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<struct node> buf;
	for (int i = 0; i < intervals.size(); ++i) {
	    struct node tmp;
	    tmp.l = intervals[i][0];
	    tmp.r = intervals[i][1];
	    buf.push_back(tmp);
	}
	sort(buf,buf.begin(),buf.end(),cmp);
	vector<vector<int>> ans;
	for (int i = 0; i < buf.size(); ++i) {
	   if(ans.empty()) {
	       vector<int> tmp;
	       tmp.push_back(buf[i].l);tmp.push_back(buf[i].r);
	       ans.push_back(tmp);
	       continue;
	   } 
	   vector<int> tmp = ans.back();
	   if(tmp[1] >= buf[i].l) {
	       ans.back()[1] = tmp[1]>buf[i].r?tmp[1]:buf[i].r;
	   } else {
	       vector<int> tt;
	       tt.push_back(buf[i].l);tt.push_back(buf[i].r);
	       ans.push_back(tt);
	   }
	}
	return ans;
    }
};

