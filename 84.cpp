class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        vector<int> l(n,0);
        vector<int> r(n,n-1);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            if (s.empty() || heights[i] > heights[s.top()]) {
                l[i] = i;
                s.push(i);
            } else {
                while(!s.empty() && heights[s.top()] >= heights[i]) {
                    s.pop();
                }
                if (!s.empty()) l[i] = s.top() +1;
                s.push(i);
            }
        }
        s = stack<int>();
        int ans = 0;
        for (int i = n-1; i>=0; --i) {
            if (s.empty() || heights[i] > heights[s.top()]) {
                r[i] = i;
                s.push(i);
            } else {
                while(!s.empty() && heights[s.top()] >= heights[i]) {
                    s.pop();
                }
                if (!s.empty()) r[i] = s.top() - 1;
                s.push(i);
            }
            if ((r[i] - l[i] + 1) * heights[i] > ans) ans = (r[i] - l[i] + 1) * heights[i];
        }
        return ans;
    }
};
