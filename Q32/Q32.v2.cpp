// Runtime: 3 ms, faster than 89.91% of C++ online submissions for Longest Valid Parentheses.
// Memory Usage: 7.5 MB, less than 16.20% of C++ online submissions for Longest Valid Parentheses.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int s_length = s.size();
        stack<int> left_pos;
        stack<char> buffer;
        int max = 0;

        buffer.push(')');
        left_pos.push(-1);
        for (int i = 0; i < s_length; i++) {
            if (s[i] == '(') {
                buffer.push(s[i]);
                left_pos.push(i);
            }
            else {
                if (buffer.top() == '('){
                    buffer.pop();
                    left_pos.pop();
                    if (i - left_pos.top() > max)
                        max = i - left_pos.top();
                }
                else
                    left_pos.push(i);
            }
        }

        return max;
    }
};

int main()
{
    Solution solution;
    string s = ")()())";
    cout << solution.longestValidParentheses(s) << endl;
}