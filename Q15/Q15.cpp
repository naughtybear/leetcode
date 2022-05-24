// Runtime: 1368 ms, faster than 8.81% of C++ online submissions for 3Sum.
// Memory Usage: 37.1 MB, less than 11.93% of C++ online submissions for 3Sum.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> nums_dict;
        vector<vector<int>> result;

        if(nums.size() < 3)
            return result;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            nums_dict[nums[i]] += 1;
        }

        for(int i=0; i<nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            if(nums[i] > 0)
                break;

            nums_dict[nums[i]] -= 1;
            for(int j=i+1; j<nums.size()-1; j++){
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;

                if (nums[j] > -nums[i] - nums[j])
                    break;

                nums_dict[nums[j]] -= 1;
                    
                if(nums_dict[-nums[i] - nums[j]] > 0){
                    vector<int> tmp{nums[i], nums[j], -nums[i] - nums[j]};
                    result.push_back(tmp);
                }
                nums_dict[nums[j]] += 1;

                if (nums[j] == -nums[i] - nums[j])
                    break;
            }
            nums_dict[nums[i]] = 0;
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> int_list = {-1,0,1,2,-1,-4,-2,-3,3,0,4};

    auto result = solution.threeSum(int_list);
    cout << endl;
    // cout << solution.threeSum(int_list)[0][0] << endl;
}