// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/submissions/1002362663/envType=study-plan-v2&envId=top-interview-150/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        int current = 0;
        int num_size = nums.size();

        for(int i = 0; i < num_size - 2; i++) {
            if(nums[i] != nums[i + 1] || nums[i] != nums[i + 2]) {
                nums[current] = nums[i];
                current++;
            }
        }
        nums[current++] = nums[num_size - 2];
        nums[current++] = nums[num_size - 1];
        return current;
    }
};