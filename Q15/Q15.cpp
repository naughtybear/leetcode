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
            if(nums[i] == 0 && nums_dict[nums[i]] < 3)
                nums_dict[nums[i]] += 1;
            else if(nums_dict[nums[i]] < 2)
                nums_dict[nums[i]] +=1;
        }

        for(int i=0; i<nums.size()-2; i++){
            nums_dict[nums[i]] -= 1;
            for(int j=i+1; j<nums.size()-1; j++){
                nums_dict[nums[j]] -= 1;
                // if (nums[j] > -nums[i] - nums[j])
                //     break;
                    
                if(nums_dict[-nums[i] - nums[j]] > 0){
                    vector<int> tmp{nums[i], nums[j], -nums[i] - nums[j]};
                    result.push_back(tmp);
                }
                nums_dict[nums[j]] += 1;

                if (nums[j+1] >= -nums[i] - nums[j+1])
                    break;
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> int_list = {-1,0,1,2,-1,-4};

    auto result = solution.threeSum(int_list);
    cout << endl;
    // cout << solution.threeSum(int_list)[0][0] << endl;
}