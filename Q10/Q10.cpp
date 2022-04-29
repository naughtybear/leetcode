#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.length()+1][p.length()+1];
        
        memset(dp, false, (s.length()+1)*(p.length()+1)*sizeof(bool));
        for(int i=1; i<p.length(); i+=2){
            if(p[i]=='*') dp[0][i+1] = true;
            else break;
        }
        dp[0][0] = true;

        for (int i=0; i<s.length(); i++){
            for (int j=0; j<p.length(); j++){
                if (p[j]=='*'){
                    if (p[j-1]==s[i] || p[j-1]=='.'){
                        if(dp[i][j+1] == true || dp[i+1][j-1] == true) dp[i+1][j+1]=true;
                        else dp[i+1][j+1] = false;
                    }
                    else dp[i+1][j+1] = dp[i+1][j-1];
                }
                else if (p[j]==s[i] || p[j]=='.'){
                    // if(i==0 && j==0) dp[i][j] = true;
                    // else if((i==0 && j!=0) || (i!=0 && j==0)) dp[i][j] = false;
                    if(dp[i][j]==true) dp[i+1][j+1] = true;
                    else dp[i+1][j+1] =false;
                }
                else{
                    dp[i+1][j+1] = false;
                }
            }
        }
        cout << endl;

        return dp[s.length()][p.length()]; 
    }
};

int main()
{
    Solution solution;

    cout << solution.isMatch("c", "d*a*b*cc*") << endl;
}