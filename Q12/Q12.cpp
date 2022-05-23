// 2022.04.29
// Runtime: 7 ms, faster than 78.70% of C++ online submissions for Integer to Roman.
// Memory Usage: 5.9 MB, less than 79.24% of C++ online submissions for Integer to Roman.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        pair<int, char> roman[7];
        string output;

        roman[0] = make_pair(1000, 'M');
        roman[1] = make_pair(500, 'D');
        roman[2] = make_pair(100, 'C');
        roman[3] = make_pair(50, 'L');
        roman[4] = make_pair(10, 'X');
        roman[5] = make_pair(5, 'V');
        roman[6] = make_pair(1, 'I');

        for(int i=0; i<7; i++){
            while (num >= roman[i].first){
                output.push_back(roman[i].second);
                num = num - roman[i].first;
            }
            if (num == 0)
                break;
            if(i%2){
                if (num >= roman[i].first - roman[i+1].first){
                    output.push_back(roman[i+1].second);
                    output.push_back(roman[i].second);
                    num = num - roman[i].first + roman[i+1].first;
                }
            }
            else{
                if (num >= roman[i].first - roman[i+2].first){
                    output.push_back(roman[i+2].second);
                    output.push_back(roman[i].second);
                    num = num - roman[i].first + roman[i+2].first;
                }
            }
        }
        
        return output;
    }
};

int main()
{
    int num = 1994;
    Solution solution;

    cout << solution.intToRoman(num) << endl;
}