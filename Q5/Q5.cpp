#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.size() == 1)
            return s;
        
        int maxStart=0, maxEnd=0, maxLen;
        int odd[s.size()], even[s.size()];

        fill_n(odd, s.size(), 0);
        fill_n(even, s.size(), 0);
        
        even[0] = 1;
        if(s[0] != s[1]){
            odd[0] = 0;
            maxLen = 1;
        }
        else{
            odd[0] = 2;
            maxLen = 2;
            maxEnd = 1;
        }
        odd[1] = 1;

        for(int i = 2; i < s.size(); i ++){
            if(i%2 == 0){
                for(int j = 0; j < i; j++){
                    if(s[i] != s[j])
                        even[j] = 0;
                    else if(i - j > 1 && odd[j+1] == 0)
                        even[j] = 0;
                    else
                        even[j] = odd[j+1] + 2;

                    if(even[j] > maxLen){
                        maxStart = j;
                        maxEnd = i;
                        maxLen = i - j +1;
                    }
                }
                even[i] = 1;
            }
            else{
                for(int j=0; j < i; j++){
                    if(s[i] != s[j])
                        odd[j] = 0;
                    else if(i - j > 1 && even[j+1] == 0)
                        odd[j] = 0;
                    else
                        odd[j] = even[j+1] + 2;
                    
                    if(odd[j] > maxLen){
                        maxStart = j;
                        maxEnd = i;
                        maxLen = i - j +1;
                    }
                }
                odd[i] = 1;
            }
        }

        return s.substr(maxStart, maxEnd - maxStart + 1);
    }
};

int main()
{
    Solution solution;
    string s="aa";

    cout << solution.longestPalindrome(s) << endl;
}