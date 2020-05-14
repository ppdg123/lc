class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int ans = 0;
        int s = 0;
        int ss = 0;
        int cnt = 0;
        bool flag = false;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > R) {
                if(flag) {
                    s += (cnt+1);
                    ss += (cnt+1)*(cnt+1);
                    ans += ((s*s) - ss)/2;
                    s = 0;
                    ss = 0;
                }
                flag = false;
		continue;
            }
            if (A[i]>=L && A[i]<=R) {
                flag = true;
                s += (cnt+1);
                ss += (cnt+1)*(cnt+1);
                cnt = 0;
            } else {
                cnt += 1;
            }
        }
        if(flag) {
            s += (cnt+1);
            ss += (cnt+1)*(cnt+1);
            ans += ((s*s) - ss)/2;
        }
        return ans;
    }
};
