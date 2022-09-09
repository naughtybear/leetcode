// Runtime: 11 ms, faster than 21.37% of C++ online submissions for Search in Rotated Sorted Array.
// Memory Usage: 11 MB, less than 75.25% of C++ online submissions for Search in Rotated Sorted Array.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int front = 0, end = nums.size() - 1;
        // int mid = (front + end) / 2;

        while (front != end) {
            int mid = (front + end) / 2;
            if (target == nums[mid])
                return mid;

            if (nums[front] <= nums[mid]) {
                if (target <= nums[mid] && nums[front] <= target) end = mid - 1;
                else front = mid + 1;
            }
            else {
                if (target >= nums[mid] && nums[end] >= target) front = mid + 1;
                else end = mid - 1; 
            }
        }

        if (target == nums[front])
            return front;

        return -1;
    }
};

int main()
{
    Solution solution;
    //vector<int> nums = {4,5,6,7,8,1,2,3};
    vector<int> nums = {1,3};
    int target = 3;

    cout << solution.search(nums, target) << endl;
}