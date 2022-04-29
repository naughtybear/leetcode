#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        long long_x = x, reverse_x = 0;

        while (x)
        {
            reverse_x = reverse_x * 10 + x%10;
            x /= 10;
        }

        if (long_x == reverse_x)
            return true;
        else
            return false;
        
    }
};

int main()
{
    Solution solution;

    cout << solution.isPalindrome(2147483647) << endl;
}