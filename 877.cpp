class Solution {
public:
    bool stoneGame(vector<int>& piles) {
         vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),0));
	 vector<int> c;
	 c.push_back(0);
	 for (int i = 0; i<piles.size(); ++i){
	     dp[i][i] = piles[i];
	     c.push_back(c.back() + piles[i]);
	 }
	 for (int i = 1; i<piles.size(); ++i) {
	     for(int j = 0; j<(piles.size()-i); ++j) {
	         int l = j;
		 int r = j+i;
		 int s = c[r+1] - c[l];
		 dp[l][r] = max(s-dp[l+1][r],s-dp[l][r-1]);
	     }
	 }
	 if (dp[0][piles.size()-1] > (c.back() - dp[0][piles.size()-1])) return true;
	 else return false;
    }
};

