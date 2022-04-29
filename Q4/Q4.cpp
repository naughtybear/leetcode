#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 一定要維持nums1 size比較小
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int left = 0;
        int right = nums1.size();
        int total_size = nums1.size() + nums2.size();

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            //cout << mid << endl;
            int x_left = (mid == 0) ? INT_MIN : nums1[mid - 1];
            int x_right = (mid == nums1.size()) ?  INT_MAX : nums1[mid];
            int y_pos = (nums1.size() + nums2.size() + 1) / 2 - mid;
            int y_left = (y_pos == 0) ? INT_MIN : nums2[y_pos - 1];
            int y_right = (y_pos == nums2.size()) ? INT_MAX : nums2[y_pos];
            //cout << left << " " << right << endl;
            //cout << x_left << " " << x_right << endl;
            //cout << y_left << " " << y_right << endl << endl;
            if(y_left > x_right){
                left = mid + 1;
            }
            else if(x_left > y_right){
                right = mid - 1;
            }
            else{
                if((nums1.size() + nums2.size()) % 2 == 0){
                    return(((double)max(x_left, y_left) + (double)min(x_right, y_right)) / 2);
                }
                else{
                    return((double)max(x_left, y_left));
                }
            }
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    vector<int> num1{}, num2{1, 2, 3, 4};
    double output;
    
    output = solution.findMedianSortedArrays(num1, num2);
    cout << output << endl;
}