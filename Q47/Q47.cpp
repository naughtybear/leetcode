// 
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
    }
};

int main()
{
    Solution solution;
    vector<int> nums {1, 2, 3};

    vector<vector<int>> output = solution.permuteUnique(nums);

    cout << output.size() << endl;
    for (int i = 0; i < output.size(); i++){
        for (auto element : output[i])
            cout << element << ", ";
        cout << endl;
    }
}