// https://leetcode.com/problems/combination-sum/submissions/839668821/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> result;
        
        result.push_back(vector<vector<int>>());
        result.push_back(vector<vector<int>>());

        for (int i = 2; i <= target; i++) {
            vector<vector<int>> tmp_list;
            for (int j = 0; j < candidates.size(); j++) {
                if (candidates[j] > i)
                    continue;
                if (candidates[j] == i){
                    tmp_list.push_back(vector<int>{i});
                }
                else {
                    for (int k = 0; k < result[i - candidates[j]].size(); k++){
                        vector<int> tmp_vector = result[i - candidates[j]][k];
                        if (tmp_vector.back() > candidates[j])
                            continue;
                        tmp_vector.push_back(candidates[j]);
                        tmp_list.push_back(tmp_vector);
                    }
                }
            }
            result.push_back(tmp_list);
        }
        return result.back();
    }
};

int main()
{
    Solution solution;
    vector<int> candidates = {2,3,5};
    
    solution.combinationSum(candidates, 8);
    //cout << vector<int>(5) << endl;
}