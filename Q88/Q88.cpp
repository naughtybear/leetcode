// https://leetcode.com/problems/merge-sorted-array/submissions/971518625/?envType=study-plan-v2&envId=top-interview-150
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            nums1.erase(nums1.begin() + m + n, nums1.end());
        }
        int current_n = 0, current_index = 0;
        nums1.insert(nums1.begin() + m, INT_MAX);

        while (current_n < n) {
            if(nums1[current_index] > nums2[current_n]) {
                nums1.insert(nums1.begin() + current_index, nums2[current_n]); 
                current_n++;
                current_index++;
            }
            else
                current_index++;
        }
        nums1.erase(nums1.begin() + m + n, nums1.end());
    }
};
int main()
{
    Solution solution;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 2;

    solution.merge(nums1, m, nums2, n);

    for (int i = 0; i < m + n; i++){
        cout << nums1[i] << endl;
    }
}