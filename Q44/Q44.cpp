// TLE
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        cout << s << endl << p << endl << "-----" << endl;
        if (s == p)
            return true;
        if(s.size() == 0){
            if (p[0] == '*') {
                p.erase(0, 1);
                return isMatch(s, p);
            }
            return false;
        }
        if(p.size() == 0)
            return false;
        
        if (p[0] == '?') {
            s.erase(0, 1);
            p.erase(0, 1);
            return isMatch(s, p);
        }
        else if (p[0] == '*'){
            string s_origin = s;
            s.erase(0, 1);
            bool tmp_result = isMatch(s, p);
            p.erase(0, 1);

            return tmp_result || isMatch(s_origin, p) || isMatch(s, p);
        }
        else {
            if (s[0] != p[0])
                return false;
            
            s.erase(0, 1);
            p.erase(0, 1);
            return isMatch(s, p);
        }
    }
};

int main()
{
    Solution solution;
    string s = "aaabababaaabaababbbaaaabbbbbbabbbbabbbabbaabbababab", p = "*ab***ba**b*b*aaab*b";

    cout << solution.isMatch(s, p) << endl;
}