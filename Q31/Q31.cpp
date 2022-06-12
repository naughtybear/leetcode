// Runtime: 8 ms, faster than 38.99% of C++ online submissions for Next Permutation.
// Memory Usage: 12.1 MB, less than 37.66% of C++ online submissions for Next Permutation.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                int change_index, tmp;
                for (int j = nums.size() - 1; j > i; j--) {
                    if(nums[j] > nums[i]){
                        change_index = j;
                        break;
                    }
                }
                tmp = nums[change_index];
                nums[change_index] = nums[i];
                nums[i] = tmp;

                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        return reverse(nums.begin(), nums.end());
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1,3,2};

    solution.nextPermutation(nums);

    for (auto i:nums) {
        cout << i << endl;
    }
}