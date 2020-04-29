class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int mp = 0;
	for (int i = 0 ; i < nums.size(); ++i) mp = mp^nums[i];
	int sp = 1;
	while ((sp&mp) == 0) sp = sp << 1;
	int a = 0, b = 0;
	for (int i = 0; i < nums.size(); ++i) {
	    if (sp&nums[i]) {a = a^nums[i];}
	    else b = b ^ nums[i];
	}
	vector<int> ans;
	ans.push_back(a); 
	ans.push_back(b);
	return ans;
    }
};
