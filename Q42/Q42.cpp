// https://leetcode.com/problems/trapping-rain-water/submissions/872954778/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        vector<int> left_max(height.size()), right_max(height.size());

        for (int i = 1; i < height.size(); i++) {
            left_max[i] = max(left_max[i - 1], height[i - 1]);
        }

        for(int i = height.size() - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], height[i + 1]);
        }

        for(int i = 0; i < height.size(); i++) {
            total += max(min(left_max[i], right_max[i]) - height[i], 0);
        }


        return total;
    }

    int trap2(vector<int>& height) {
        int right_idx = height.size() - 2, left_idx = 1;
        int right_max = height[right_idx + 1], left_max = height[left_idx - 1];
        int total = 0;

        while(left_idx <= right_idx) {
            if(left_max < right_max) {
                if (height[left_idx] > left_max)
                    left_max = height[left_idx];
                else {
                    total += left_max - height[left_idx];
                }
                left_idx++;
            }
            else{
                if (height[right_idx] > right_max) {
                    right_max = height[right_idx];
                }
                else {
                    total += right_max - height[right_idx];
                }
                right_idx--;
            }
        }

        return total;
    }
};

int main()
{
    Solution solution;
    vector<int> height = {4,2,0,3,2,5};

    cout << solution.trap2(height) << endl;
}