// https://leetcode.com/problems/permutations/submissions/890370423/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result, tmp;
        result.push_back(vector<int>{nums[0]});
        
        for (int i = 1; i < nums.size(); i++) {
            for (auto num_list : result) {
                for (int j = 0; j <= num_list.size(); j++) {
                    auto tmp_list = num_list;
                    tmp_list.insert(tmp_list.begin() + j, nums[i]);
                    tmp.push_back(tmp_list);
                }
            }
            result = tmp;
            tmp.clear();
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums {1, 2, 3};

    vector<vector<int>> output = solution.permute(nums);

    cout << output.size() << endl;
    for (int i = 0; i < output.size(); i++){
        for (auto element : output[i])
            cout << element << ", ";
        cout << endl;
    }
}