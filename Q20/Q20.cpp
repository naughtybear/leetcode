// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
// Memory Usage: 6.4 MB, less than 51.91% of C++ online submissions for Valid Parentheses.
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket_stack;


        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                bracket_stack.push(s[i]);
            }
            else{
                if (bracket_stack.empty() || (s[i] == ')' && bracket_stack.top() != '(') || (s[i] == ']' && bracket_stack.top() != '[') || (s[i] == '}' && bracket_stack.top() != '{')){
                    return false;
                }
                else
                    bracket_stack.pop();
            }
        }
        if (bracket_stack.empty())
            return true;
        else
            return false;
    }
};
int main()
{
    Solution solution;
    string s = "]";

    cout << solution.isValid(s) << endl;
}