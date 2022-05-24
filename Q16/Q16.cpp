// Runtime: 20 ms, faster than 64.00% of C++ online submissions for 3Sum Closest.
// Memory Usage: 9.9 MB, less than 99.27% of C++ online submissions for 3Sum Closest.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result, dif = INT_MAX;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++){
            int front = i + 1;
            int back = nums.size() - 1;

            while (back > front) {
                int sum = nums[i] + nums[front] + nums[back];
                if (abs(sum - target) < dif){
                    dif = abs(sum - target);
                    result = sum;
                }
                if (sum > target) back--;
                else if (sum < target) front++;
                else{
                    result = target;
                    break;
                }
            }

            if(result == target)
                break;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> int_list = {0, 0, 0};

    cout << solution.threeSumClosest(int_list, 1) << endl;
}