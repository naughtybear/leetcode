// https://leetcode.com/problems/jump-game-ii/submissions/890347520/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        const int nums_size = nums.size();
        int jump = 0, max_current = 0, max_next = 0;
        
        for (int i = 0; i < nums_size - 1; i++) {
            max_next =  max(max_next, nums[i] + i);
            if (i == max_current) {
                max_current = max_next;
                jump++;
            }
        }

        return jump;
    }
};

int main()
{
    Solution solution;
    vector<int> nums {2,1};

    cout << solution.jump(nums) << endl;
}