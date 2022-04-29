#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0, end=height.size()-1, max_size=0;

        while (1)
        {
            max_size = max(min(height[start], height[end]) * (end - start), max_size);

            if(height[start] < height[end]){
                int tmp = start+1;

                while (tmp < end && height[tmp] <= height[start])
                {
                    tmp++;
                }

                if(tmp >= end) break;
                start = tmp;
            }
            else {
                int tmp = end-1;

                while (tmp > start && height[tmp] <= height[end])
                {
                    tmp--;
                }

                if(tmp <= start) break;
                end = tmp;
            }
        }
        return max_size;
    }
};

int main()
{
    Solution solution;
    vector<int> height{1,1};

    cout << solution.maxArea(height) << endl;
}