// 2022.04.29
// Runtime: 26 ms, faster than 22.52% of C++ online submissions for Roman to Integer.
// Memory Usage: 8.4 MB, less than 12.77% of C++ online submissions for Roman to Integer.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman_number_map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int i=0, total=0;

        while (i < s.length())
        {
            if(roman_number_map[s[i]] < roman_number_map[s[i+1]]){
                total += roman_number_map[s[i+1]] - roman_number_map[s[i]];
                i += 2;
            }
            else{
              total += roman_number_map[s[i]];
              i += 1;
            }
        }
        return total;   
    }
};

int main()
{
    string num = "LVIII";
    Solution solution;

    cout << solution.romanToInt(num) << endl;
}