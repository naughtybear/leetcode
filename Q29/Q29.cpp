// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Divide Two Integers.
// Memory Usage: 5.8 MB, less than 76.26% of C++ online submissions for Divide Two Integers.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        int sign = signbit(dividend) == signbit(divisor) ? 1 : -1;
        long long_dividend = labs(dividend);
        long long_divisor = labs(divisor);
        long result = 0;

        while (long_dividend >= long_divisor) {
            long tmp = long_divisor, mul = 1;
            while (tmp << 1 <= long_dividend) {
                tmp <<= 1;
                mul <<= 1;
            }
            long_dividend -= tmp;
            result += mul;
        }
        return int(sign * result);
    }
};

int main()
{
    Solution solution;

    cout << solution.divide(-2147483648, 1) << endl;
}