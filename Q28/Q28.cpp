// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement strStr().
// Memory Usage: 6.2 MB, less than 90.94% of C++ online submissions for Implement strStr().
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int h_size = haystack.size();
        int n_size = needle.size();

        if (h_size < n_size)
            return -1;

        for (int i = 0; i < h_size - n_size + 1; i++) {
            if (needle[0] == haystack[i]) {
                bool flag = true;
                for (int j = 1; j < n_size; j++) {
                    // if (i + j > haystack.size())
                    //     return -1;
                    if (haystack[i + j] != needle[j])
                        flag = false;
                }
                if (flag)
                    return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    string haystack = "hello";
    string needle = "llo";

    cout << solution.strStr(haystack, needle) << endl;
}