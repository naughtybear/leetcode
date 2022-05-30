// Runtime: 4 ms, faster than 41.22% of C++ online submissions for Remove Element.
// Memory Usage: 8.9 MB, less than 36.71% of C++ online submissions for Remove Element.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
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
    int k = solution.removeElement(nums, 2);

    // cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << nums[i] << endl;
    }
}