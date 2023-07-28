// https://leetcode.com/problems/first-missing-positive/submissions/841789139/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] <= 0 || nums[i] > n)
                nums[i] = n + 1;
        }

        for(int i = 0; i < n; i++){
            if(abs(nums[i]) < n + 1) {
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
            }
        }

        for(int i = 0; i < n; i++){
            if(nums[i] > 0)
                return i + 1;
        }

        return n + 1;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {3,4,-1,1};

    cout << solution.firstMissingPositive(nums);
}