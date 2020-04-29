/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    void bheep(MountainArray &mountainArr,int l , int r) {
        if(l > r) return;
	if (l == r) {
	    h = l;
	    return;
	}
        int m = (l+r) / 2;
	int vm = mountainArr.get(m);
	int vr = mountainArr.get(m+1);
	if (vm < vr) {
	    bheep(mountainArr,m+1,r);
	} else {
	    bheep(mountainArr,l,m);
	}
    }
    void bsearch(MountainArray &mountainArr,int l , int r, int target, bool asc) {
        if (l > r) return;
        int m = (l+r)/2;
	int v = mountainArr.get(m);
	if (ans >=0) return ;
	if (v == target) {
	    ans = m;
	    return;
	}
	if (target < v) {
	    if (asc)
	        bsearch(mountainArr,l,m-1,target,asc);
	    else 
	        bsearch(mountainArr,m+1,r,target,asc);
	} else {
	    if (asc)
	        bsearch(mountainArr,m+1,r,target,asc);
	    else 
	        bsearch(mountainArr,l,m-1,target,asc);
	}
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
         h = -1;
	 ans = -1;
	 bheep(mountainArr,0,mountainArr.length()-1);
	 bsearch(mountainArr,0,h,target,true);
	 if (ans >=0) return ans;
	 bsearch(mountainArr,h+1,mountainArr.length()-1,target,false);
	 return ans;
    }
    int h;
    int n;
    int ans;
};

