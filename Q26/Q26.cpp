// Runtime: 15 ms, faster than 64.80% of C++ online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 18.3 MB, less than 75.04% of C++ online submissions for Remove Duplicates from Sorted Array.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]){
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = solution.removeDuplicates(nums);

    // cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << nums[i] << endl;
    }
}