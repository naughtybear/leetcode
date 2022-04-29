#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        int output = 0;

        while (x)
        {
            if (output > INT_MAX / 10)
                return 0;
            if (output < INT_MIN / 10)
                return 0;
            output = output * 10 + x % 10;
            x = x / 10;
        }

        return output;
    }
};

int main()
{
    Solution solution;

    string a = "I'm 87 simon";

    cout << a << endl;
    cout << "hehe 87 simon" << endl;
    cout << solution.reverse(-2147483642) << endl;

    // cout << -123 % 10;
}