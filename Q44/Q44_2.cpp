//https://leetcode.com/problems/wildcard-matching/submissions/889903743/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size = s.size(), p_size = p.size();
        bool DP[s_size + 1][p_size + 1];

        // init
        DP[0][0] = true;
        for (int i = 1; i <= s_size; i++){
            DP[i][0] = false;
        }
        for (int i = 1; i <= p_size; i++) {
            if (p[p_size - i] == '*') {
                DP[0][i] = DP[0][i - 1];
            }
            else
                DP[0][i] = false;
        }

        // iter
        for (int i = 1; i <= s_size; i++){
            for (int j = 1; j <= p_size; j++) {
                if (p[p_size - j] == '*'){
                    DP[i][j] = DP[i][j - 1] || DP[i - 1][j]; 
                }
                else if (p[p_size - j] == '?') {
                    DP[i][j] = DP[i - 1][j - 1];
                }
                else {
                    if (s[s_size - i] == p[p_size - j]) {
                        DP[i][j] = DP[i - 1][j - 1];
                    }
                    else{
                        DP[i][j] = false;
                    }
                }
            }
        }

        return DP[s_size][p_size];
    }
};

int main()
{
    Solution solution;
    string s = "adceb", p = "*a*b";

    cout << solution.isMatch(s, p) << endl;
}