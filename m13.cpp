class Solution {
public:
    bool canin(int a, int b, int k) {
         int tmp = 0;
         while (a) {tmp += a%10; a/=10;}
         while (b) {tmp += b%10; b/=10;}
	 if (tmp > k) return false;
	 return true;
    }
    void dfs(int a, int b,int m , int n,int k) {
        if (a < 0 || a >= m || b< 0 || b >=n) return;
        if (vis[a][b]) return;
	if (canin(a,b,k)) {
	    ans ++;
	}
	vis[a][b] = true;
	dfs(a-1,b,m,n,k);
	dfs(a,b-1,m,n,k);
	dfs(a+1,b,m,n,k);
	dfs(a,b+1,m,n,k);
    }
    int movingCount(int m, int n, int k) {
        ans = 0;
	memset(vis,0,sizeof(vis));
	dfs(0,0,m,n,k);
	return ans;
    }
    int ans;
    bool vis[101][101];
};
