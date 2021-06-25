class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a, int b) {
	    long l = 10;
	    while(l <= a) l*=10;
	    long r = 10;
	    while(r <= b) r*=10;
	    return (l*b +a) > (r*a+b);
	});
	string ans;
	for(int i = 0; i < nums.size(); ++i) {
	    ans += to_string(nums[i]);
	}
	if (ans[0] == '0') return "0";
	return ans;
    }
};
