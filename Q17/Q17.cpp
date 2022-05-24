// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
// Memory Usage: 6.7 MB, less than 18.51% of C++ online submissions for Letter Combinations of a Phone Number.
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return vector<string>();

        map<char, string> digToLet{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"} 
        };
        vector<string> result{""};

        for (int i = 0; i < digits.size(); i++){
            vector<string> tmp;
            for (int j = 0; j < result.size(); j++){
                for (int k = 0; k < digToLet[digits[i]].size(); k++){
                    tmp.push_back(result[j] + digToLet[digits[i]][k]);
                }
            }
            result = tmp;
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> result = solution.letterCombinations("23");
    
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
}