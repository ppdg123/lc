class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (first.size() == second.size()) {
	    int cnt = 0;
	    for(int i = 0; i<first.size(); i++) {
	        if (first[i] != second[i]) cnt++;
		if (cnt > 1) return false;
	    }
	    return true;
	} else {
	    int cnt = 0;
	    int i = 0, j = 0;
	    while (i < first.size() && j < second.size()) {
	        if (first[i] != second[i]) {
		    cnt ++;
		    if (first.size() > second.size()) i++;
		    else j++;
		    if (cnt > 1) return false;
		    continue;
		}
		i++; j++;
	    }
	    cnt += (first.size()-i);
	    cnt += (second.size()-j);
	    if (cnt > 1) return false;
	    return true;
	}
    }
};
