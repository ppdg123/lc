class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int h = 1;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int cur = heaters[0];
        int nxt = INT_MAX;
        if (heaters.size() > 1) nxt = heaters[1];
        int ans = INT_MIN;
        for (int i = 0; i < houses.size(); ++i) {
            while(abs(houses[i] - cur) >= abs(houses[i] - nxt) && nxt != INT_MAX) {
               ++h;
               if (h < heaters.size()) {
                   cur = nxt;
                   nxt = heaters[h];
               } else {
                   cur = nxt;
                   nxt = INT_MAX;
               }
            }
            if (ans < abs(houses[i] - cur)) {
                ans = abs(houses[i] - cur);
            }
        }
        return ans;
    }
};
