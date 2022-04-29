#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int repeat = 0;
        int storage[128];
        int max_sub_len = 0;

        for(int i=0; i < 128; i++){
            storage[i] = -1;
        }

        for(int i=0; i < s.length(); i++){
            if(repeat <= storage[s[i]]){
                max_sub_len = max_sub_len > i - repeat ? max_sub_len : i - repeat;
                repeat = storage[s[i]] + 1;
            }
            storage[s[i]] = i;
            //cout << repeat << endl;
        }
        return max_sub_len > s.length() - repeat ? max_sub_len : s.length() - repeat;
    }
};

int main()
{
    Solution solution;
    string input = "wwdwq";
    int output;

    output = solution.lengthOfLongestSubstring(input);
    cout << output << endl;
}