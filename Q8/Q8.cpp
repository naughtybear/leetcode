#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int output = 0, start = 0;
        int sign = 1;

        while (s[start] == ' '){
            start++;
        }
        
        if (s[start] == '-'){
            sign = -1;
            start++;
        }
        else if(s[start] == '+'){
            start++;
        }

        for (int i=start; i<s.length(); i++){
            if (s[i]>'9' || s[i]<'0') break;
            if (sign == 1 && (output > INT_MAX / 10 || (output == INT_MAX / 10 && s[i] > '6')))
                return INT_MAX;
            if (sign == -1 && (output > INT_MAX / 10 || (output == INT_MAX / 10 && s[i] > '7')))
                return INT_MIN;

            output = output * 10 + (s[i] - '0');
        }
        output = output * sign;

        return output;
    }
};

int main()
{
    Solution solution;
    string input="   -2147483648";

    cout << solution.myAtoi(input) << endl;
}