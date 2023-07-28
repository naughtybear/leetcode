// https://leetcode.com/problems/multiply-strings/submissions/872974217/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" or num2 == "0") {
            return "0";
        }
        string result(num1.size() + num2.size(), 0);
        
        for (int i = 0; i < num1.size(); i++) {
            for(int j = 0; j < num2.size(); j++){
                result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                if (result[i + j + 1] > 9) {
                    int tmp = result[i + j + 1];
                    result[i + j + 1] = tmp % 10;
                    result[i + j] += tmp / 10;
                }
            }
        }

        for(int i = num1.size() + num2.size() - 1; i >= 0; i--){
            if(result[i] > 9) {
                int tmp = result[i];
                result[i] = tmp % 10 + '0';
                result[i - 1] += tmp / 10;
            }
            else{
                result[i] = result[i] + '0';
            }
        }

        if(result[0] == '0'){
            result.erase(0, 1);
        }

        return result;
    }
};

int main()
{
    Solution solution;
    string num1 = "999", num2 = "0";

    cout << solution.multiply(num1, num2);
}