#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap<int, int> map_nums;
        vector<int> output;
        int len = nums.size();
        
        for(int i = 0; i < len; i++){
            //cout << nums[i] << " " << i << endl;
            map_nums.insert(pair<int, int>(nums[i], i));
        }
        for(auto i = map_nums.begin(); i != map_nums.end(); i++){
            int num1 = i -> first, num2 = i->second;
            map_nums.erase(i);
            auto find_result = map_nums.find(target - num1);
            // cout << target - i->first << endl;
            // cout << find_result -> first << " " << find_result -> second << endl;
            if(find_result != map_nums.end()){
                output.push_back(num2);
                output.push_back(find_result -> second);
                break;
            }
        }
        return output;
    }
};

int main()
{
    vector<int> input{3, 3};
    vector<int> output;
    Solution solution;
    int target = 6;

    output = solution.twoSum(input, target);
    for(auto i = output.begin(); i != output.end(); i++){
        cout << *i << ' ';
    }
    cout << endl;
}