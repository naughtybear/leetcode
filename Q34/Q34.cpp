// Runtime: 10 ms, faster than 75.91% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 13.7 MB, less than 63.74% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result = {-1, -1};

        if (nums.size() == 0)
            return result;

        int front = 0, end = nums.size()-1;
        int mid;

        while (front != end) {
            mid = (front + end) / 2;
            if (target > nums[mid]) {
                front = mid + 1;
            }
            else {
                end = mid;
            }
        }

        if (target != nums[front])
            return result;
        
        result[0] = front;
        front = 0, end = nums.size()-1;

        while (front != end) {
            mid = (front + end) / 2;
            if (target >= nums[mid]) {
                front = mid + 1;
            }
            else {
                end = mid;
            }
        }

        if (target != nums[front])
            front--;
        result[1] = front;

        return result;   
    }
};


int main()
{
    Solution solution;
    vector<int> nums = {5,7,7,8,8,8,10,10};
    // vector<int> nums = {7,7,7,7,7,7,7,7,7,7};
    // vector<int> nums = {1, 4};
    int target = 8;

    // cout << "!";
    cout << solution.searchRange(nums, target)[0] << " " << solution.searchRange(nums, target)[1] << endl;
}