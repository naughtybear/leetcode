// https://leetcode.com/problems/rotate-array/submissions/1005971918/?envType=study-plan-v2&envId=top-interview-150
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int num_size = nums.size();
        k = k % num_size;
        if (k == 0)
            return;

        int tmp[k];
        for (int i = num_size - k; i < num_size; i++)
            tmp[i - num_size + k] = nums[i];
        for (int i = num_size - 1; i >= k; i--)
            nums[i] = nums[i - k];
        for (int i = 0; i < k; i++)
            nums[i] = tmp[i];
    }
};