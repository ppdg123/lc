class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int ans[5001];
	if(amount == 0) return 1;
        memset(ans,0,sizeof(ans));
        for (int i = 0; i<coins.size(); ++i) {
            ans[coins[i]] ++;
            for (int j = coins[i]+1; j<= amount; ++j){
                ans[j] += ans[j-coins[i]];
            }
        }
        return ans[amount];
    }
};
