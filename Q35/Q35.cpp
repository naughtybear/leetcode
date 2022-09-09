// Runtime: 6 ms, faster than 68.41% of C++ online submissions for Search Insert Position.
// Memory Usage: 9.6 MB, less than 71.96% of C++ online submissions for Search Insert Position.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int front = 0, back = nums.size();
        int mid;

        while (front != back) {
            mid = (front + back) / 2;

            if (nums[mid] == target)
                return mid;

            if (target > nums[mid]) {
                front = mid + 1;
            }
            else {
                back = mid;
            }
        }       
        return front;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {6};
    // vector<int> nums = {7,7,7,7,7,7,7,7,7,7};
    // vector<int> nums = {1, 4};
    int target = 8;

    cout << solution.searchInsert(nums, target)<< endl;
}