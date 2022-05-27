// Runtime: 101 ms, faster than 48.97% of C++ online submissions for 4Sum.
// Memory Usage: 13.2 MB, less than 76.40% of C++ online submissions for 4Sum.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        if (nums.size() < 4)
            return result;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++){
            
            // 加入這些判斷會加快： Runtime: 40 ms, faster than 92.39% of C++ online submissions for 4Sum.
            // if(i > 0 && nums[i] == nums[i - 1]) continue;
            // if(nums[i] + nums[i + 1] > target - nums[i + 2] - nums[i + 3]) break;
            // if(nums[i]+nums[nums.size() - 3] < target - nums[nums.size() - 2] - nums[nums.size() - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++){
                int front = j + 1;
                int back = nums.size() - 1;

                // result.push_back(vector<int>{0 ,0 ,0 ,0});
                while(front < back){
                    int sums = nums[front] + nums[back]; // 要小心overflow

                    if (sums > target - nums[i] - nums[j]){
                        back --;
                    }
                    else if (sums < target - nums[i] - nums[j]){
                        front++;
                    }
                    else{
                        vector<int> tmp{nums[i], nums[j], nums[front], nums[back]};

                        result.push_back(tmp);

                        while (front < back && nums[front] == tmp[2]) front++;
                        while (front < back && nums[back] == tmp[3]) back--;
                    }
                }
                while (j < nums.size() - 2 && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
            while (i < nums.size() - 3 && nums[i] == nums[i + 1]) {
                i++;
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> int_list = {2,2,2,2,2};

    auto result = solution.fourSum(int_list, 8);
    cout << endl;
    // cout << solution.threeSum(int_list)[0][0] << endl;
}