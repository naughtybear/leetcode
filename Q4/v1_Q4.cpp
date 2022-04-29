#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_length = nums1.size() + nums2.size();
        int sorted_nums[total_length];
        int idx1 = 0, idx2 = 0, idx3 = 0;
        
        while (idx1 < nums1.size() && idx2 < nums2.size())
        {
            if(nums1[idx1] > nums2[idx2]){
                sorted_nums[idx3]= nums2[idx2];
                idx2++;
            }
            else{
                sorted_nums[idx3] = nums1[idx1];
                idx1++;
            }
            idx3++;
        }
        if(idx1 < nums1.size()){
            for(int i = idx1; i < nums1.size(); i++){
                sorted_nums[idx3] = nums1[i];
                idx3++;
            }
        }
        else{
            for(int i = idx2; i < nums2.size(); i++){
                sorted_nums[idx3] = nums2[i];
                idx3++;
            }
        }

        if(total_length % 2)
            return sorted_nums[(total_length - 1) / 2];
        else{
            return (double)(sorted_nums[total_length / 2] + sorted_nums[total_length / 2 - 1]) / 2;
        }
    }
};

int main()
{
    Solution solution;
    vector<int> num1{1}, num2{2, 3, 4};
    double output;
    
    output = solution.findMedianSortedArrays(num1, num2);
    cout << output << endl;
}