// Runtime: 125 ms, faster than 52.98% of C++ online submissions for 3Sum.
// Memory Usage: 21.2 MB, less than 45.05% of C++ online submissions for 3Sum.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        if(nums.size() < 3)
            return result;
        
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++){
            int front = i + 1, back = nums.size() - 1;
            int target = -nums[i];
            
            while (front < back){
                int sum = nums[front] + nums[back];
                if(target > sum)  front++;
                else if(target < sum) back--;
                else{
                    vector<int> tmp = {nums[i], nums[front], nums[back]};
                    result.push_back(tmp);
                    while(front < back && nums[front] == tmp[1]) front++;
                    while(front < back && nums[back] == tmp[2]) back--;
                }
            }
            while (i<nums.size()-2 && nums[i] == nums[i+1]){
                i++;
            }
            
        }
    
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> int_list = {0, 0, 0};

    auto result = solution.threeSum(int_list);
    cout << endl;
    // cout << solution.threeSum(int_list)[0][0] << endl;
}