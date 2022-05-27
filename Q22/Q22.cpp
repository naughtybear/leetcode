// Runtime: 18 ms, faster than 10.40% of C++ online submissions for Generate Parentheses.
// Memory Usage: 18.7 MB, less than 8.30% of C++ online submissions for Generate Parentheses.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output = {""};
        vector<queue<char>> que_list;

        que_list.push_back(queue<char>());
        // cout << que_list[0].empty();
        
        for (int i = 0; i < n; i++){
            vector<string> tmp_output;
            vector<queue<char>> tmp_queue_list;
            for (int j = 0; j < output.size(); j++) {
                // queue<char>tmp_queue = que_list[j]

                if (que_list[j].empty()) {
                    tmp_output.push_back(output[j] + '(');
                    que_list[j].push('(');
                    tmp_queue_list.push_back(que_list[j]);
                }
                else {
                    while (!que_list[j].empty()) {
                        queue<char> tmp = que_list[j];

                        tmp_output.push_back(output[j] + '(');
                        tmp.push('(');
                        tmp_queue_list.push_back(tmp);

                        output[j] += ')';
                        que_list[j].pop();
                    }
                    tmp_output.push_back(output[j] + '(');
                    que_list[j].push('(');
                    tmp_queue_list.push_back(que_list[j]);
                }
            }
            output = tmp_output;
            que_list = tmp_queue_list;
        }

        for (int i = 0; i < output.size(); i++) {
            while (!que_list[i].empty()) {
                output[i] += ')';
                que_list[i].pop();
            }
        }

        return output;
    }
};

int main()
{
    Solution solution;

    vector<string> output = solution.generateParenthesis(3);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
}