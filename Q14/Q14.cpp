// Runtime: 4 ms, faster than 73.06% of C++ online submissions for Longest Common Prefix.
// Memory Usage: 9.2 MB, less than 78.69% of C++ online submissions for Longest Common Prefix.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_length = 500;
        string result = "";

        if(strs.size() == 1)
            return strs[0];

        for(int i=0; i<strs.size(); i++){
            if(min_length > strs[i].length()){
                min_length = strs[i].length();
            }
        }

        if(min_length == 0)
            return result;

        for(int i=0; i<min_length; i++){
            bool flag = false;
            for(int j=1; j<strs.size(); j++){
                if(strs[j][i] != strs[j-1][i]){
                    flag = true;
                    break;
                }
            }

            if(flag)
                break;
            
            result.push_back(strs[0][i]);
        }

        return result;
    }
};

int main()
{
    
    Solution solution;
    vector<string> string_list = {"flower","flow","flight"};

    cout << solution.longestCommonPrefix(string_list) << endl;
}