#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void fsort(vector<int>& nums, int beg, int end) {
        int mid = beg;
        int i = beg+1;
        int j = end;
        if (i > j) return;
        while (i<=j) {
            while(i<=j && nums[i] <= nums[mid]) i++;
            while(i<=j && nums[j] > nums[mid]) j--;
            if (i <= j) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        int tmp = nums[mid];
        nums[mid] = nums[j];
        nums[j] = tmp;
        fsort(nums, beg, j-1);
        fsort(nums, j+1, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        fsort(nums,0,nums.size()-1);
        return nums;
    }
};

int main(){
    class Solution a;
    vector<int> nums = {0,0,0,0};
    a.sortArray(nums);
    for (int i = 0 ; i < nums.size(); ++i) {
        printf("%d ",nums[i]);
    }
    printf("\n");
    return 0;
}