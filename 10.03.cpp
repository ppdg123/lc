class Solution {
public:
    int search(vector<int>& arr, int target) {
	vector<int> ar;
	vector<int> id;
	for (int i = 0; i<arr.size(); ++i) {
	    if (ar.empty()) {
	        ar.push_back(arr[i]);
		id.push_back(i);
	    } else {
	        if(arr[i] != ar.back()) {
		    ar.push_back(arr[i]);
		    id.push_back(i);
		}
	    }
	}
	int l = 0;
	int r = ar.size()-1;
	int m;
	if(ar.size() > 1 && ar[0] == ar.back()) r--;
	while(l<=r) {
	    m = (l+r)/2;
	    if (ar[m] == target) return id[m];
	    if (ar[m] < target) {
	        if (ar[m] < ar[r]) {
		    if(target <= ar[r]) {
		        l = m+1;
		    } else {
		        r = m-1;
		    }
		} else {
		    l = m+1;
		}
	    } else {
	        if (ar[m] < ar[r]) {
		    r = m-1;
		} else {
		    if(target >= ar[l]) {
		        r = m-1;
		    } else {
		        l = m+1;
		    }
		}
	    }
	}
	return -1;
    }
};
