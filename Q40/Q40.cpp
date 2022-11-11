// https://leetcode.com/problems/combination-sum-ii/submissions/841590516/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> get_tmp_result(vector<int>& candidates, int target, int idx, int sum) {
        vector<vector<int>> list;
        // return list;
    
        if (idx == candidates.size() - 1) {
            return list;
        }

        for (int i = idx + 1; i < candidates.size(); i++){
            if (sum + candidates[i] == target) {
                list.push_back(vector<int> {candidates[i]});
                break;
            }
            if (sum + candidates[i] > target)
                break;

            if (i > idx + 1 && candidates[i] == candidates[i - 1])
                continue;

            vector<vector<int>> tmp_list = get_tmp_result(candidates, target, i, sum + candidates[i]);

            for(int j = 0; j < tmp_list.size(); j++){
                vector<int> tmp = tmp_list[j];
                tmp.push_back(candidates[i]);
                list.push_back(tmp);
                // cout << "a" << endl;
            }
            // cout << "a" << endl;
        }
        return list;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result = get_tmp_result(candidates, target, -1, 0);
        sort(result.begin(), result.end());
        result.erase(unique( result.begin(), result.end() ), result.end());
        //cout << "a" << endl;

        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> candidates = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    
    solution.combinationSum2(candidates, 30);
}