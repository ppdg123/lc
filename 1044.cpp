#define N 100001
char s[N];                          // N > 256
int n, sa[N], height[N], rk[N], tmp[N], top[N];
void makesa()                       // O(N * log N)
{
        int i, j, len, na;
        na = (n < 256 ? 256 : n);
        memset(top, 0, na * sizeof(int));
        for (i = 0; i < n ; i++) top[ rk[i] = s[i] & 0xff ]++;
        for (i = 1; i < na; i++) top[i] += top[i - 1];
        for (i = 0; i < n ; i++) sa[ --top[ rk[i] ] ] = i;
        for (len = 1; len < n; len <<= 1) {
                for (i = 0; i < n; i++) {
                        j = sa[i] - len; if (j < 0) j += n;
                        tmp[ top[ rk[j] ]++ ] = j;
                }
                sa[ tmp[ top[0] = 0 ] ] = j = 0;
                for (i = 1; i < n; i++) {
                        if (rk[ tmp[i] ] != rk[ tmp[i-1] ] ||
                                rk[ tmp[i]+len ]!=rk[ tmp[i-1]+len ])
                                top[++j] = i;
                        sa[ tmp[i] ] = j;
                }
                memcpy(rk, sa , n * sizeof(int));
                memcpy(sa  , tmp, n * sizeof(int));
                if (j >= n - 1) break;
        }
}
void lcp()                          // O(4 * N)
{
        int i, j, k;
        for (j = rk[height[i=k=0]=0]; i < n - 1; i++, k++)
                while (k >= 0 && s[i] != s[ sa[j-1] + k ])
                        height[j] = (k--), j = rk[ sa[j] + 1 ];
}

class Solution {
public:
    string longestDupSubstring(string S) {
        n = S.size()+1;
        strcpy(s,S.c_str());
        makesa();
        lcp();
        int ans = 0;
	int idx = 0;
        string anss;
        for(int i = 0; i<n; ++i){
            if (height[i] > ans) {
                ans = height[i];
		idx = sa[i];
            }
        }
        return S.substr(idx,ans);;
    }
};
