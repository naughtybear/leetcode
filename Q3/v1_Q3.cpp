#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head = 0;
        int tail = 0;
        unordered_set<int> storage;
        int string_len = s.length();
        int max_sub_len = 0;

        while (tail < string_len)
        {
            if(storage.end() == storage.find(s[tail])){
                storage.insert(s[tail]);
                tail++;
                max_sub_len = max_sub_len < storage.size() ? storage.size() : max_sub_len;
            }
            else{
                storage.erase(s[head]);
                head++;
            }
        }
        return max_sub_len;
    }
};

int main()
{
    Solution solution;
    string input = "sadfghj";
    int output;

    output = solution.lengthOfLongestSubstring(input);
    cout << output << endl;
}