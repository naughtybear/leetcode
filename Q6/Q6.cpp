#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int num = numRows == 1 ? 1 : 2 * (numRows - 1);
        string output = "";
        
        for(int i=0; i < s.length(); i+=num){
            output.push_back(s[i]);
        }
        
        for(int i=1; i < numRows - 1; i++){
            for(int j=i; j < s.length(); j+=num){
                output.push_back(s[j]);
                if(j+2*(numRows-i-1)<s.length()){
                    output.push_back(s[j+2*(numRows-i-1)]);
                }
            }
        }

        if(numRows > 1){
            for(int i=numRows-1; i < s.length(); i+=num){
                output.push_back(s[i]);
            }
        }

        return output;
    }
};

int main()
{
    Solution solution;
    string s="ABABABABAB";

    cout << solution.convert(s, 1) << endl;
}