#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    struct node {
        int x, y;
    };
    vector<struct node> s;
    int trap(vector<int>& height) {
        s.clear();
	ans = 0;
	int i = 0;
	int used = 0;
	while (i < height.size()) {
	    if(s.size() < 1) {
	        struct node tmp;
		tmp.x = i;
		tmp.y = height[i];
		s.push_back(tmp);
		i++;
		used = 0;
	    } else {
	        struct node b = s.back();
		if (height[i] >= b.y) {
		     ans += (b.y - used) * (i-b.x-1);
		     used = b.y;
		     s.pop_back();
		} else {
		     ans += (height[i] - used) *(i-b.x-1);
		     struct node tmp;
		     tmp.x = i;
		     tmp.y = height[i];
		     s.push_back(tmp);
		     used = 0;
		     i++;
		}
	    }
	}
	return ans;
    }
    int ans = 0;
};

int main(){
    Solution a;
    vector<int> aa= {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << a.trap(aa) << endl;
    return 0;
}
