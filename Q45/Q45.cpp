// https://leetcode.com/problems/jump-game-ii/submissions/890304517/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        const int nums_size = nums.size();
        vector<int> hop(nums_size + 1000, 10000);

        hop[0] = 0;
        for (int i = 0; i < nums_size; i++) {
            for (int j = i; j <= i + nums[i]; j++) {
                if (hop[i] + 1 < hop[j])
                    hop[j] = hop [i] + 1;
            }
        }

        return hop[nums_size - 1];
    }
};

int main()
{
    Solution solution;
    vector<int> nums {2,3,1,1,4};

    cout << solution.jump(nums) << endl;
}