// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count and Say.
// Memory Usage: 6.6 MB, less than 78.50% of C++ online submissions for Count and Say.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; i++) {
            int count = 1;
            char current = result[0];
            string tmp = "";
            for(int j = 1; j < result.length(); j++){
                if (result[j] == current)
                    count ++;
                else {
                    tmp += count + '0';
                    tmp += current;
                    count = 1;
                    current = result[j];
                }
            }
            tmp += count + '0';
            tmp += current;
            result = tmp;
            tmp = "";
        }

        return result;
    }
}; 

int main()
{
    Solution solution;

    cout << solution.countAndSay(4) << endl;
}