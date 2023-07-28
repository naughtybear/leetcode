// https://leetcode.com/problems/majority-element/submissions/1005929803/?envType=study-plan-v2&envId=top-interview-150
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> element_count;
        int nums_size = nums.size();

        for(int i = 0; i < nums_size; i++) {
            if (element_count.find(nums[i]) != element_count.end())
                element_count[nums[i]]++;
            else
                element_count[nums[i]] = 1;
            if (element_count[nums[i]] > nums_size / 2)
                return nums[i];
        }
        return 0;
    }

    int majorityElement_better(vector<int>& nums) {
        int major=nums[0], count = 1;
        for(int i=1; i<nums.size();i++){
            if(count==0){
                count++;
                major=nums[i];
            }else if(major==nums[i]){
                count++;
            }else count--;
            
        }
        return major;
    }
};