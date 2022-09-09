// Runtime: 35 ms, faster than 57.46% of C++ online submissions for Valid Sudoku.
// Memory Usage: 18.2 MB, less than 64.77% of C++ online submissions for Valid Sudoku.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0), column(9, 0), block(9, 0);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.') {
                    int num = 1 << board[i][j] - '0';
                    int block_idx = (i / 3) * 3 + j / 3;

                    if (row[i] & num || column[j] & num || block[block_idx] & num)
                        return false;
                    
                    row[i] |= num;
                    column[j] |= num;
                    block[block_idx] |= num;
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','9','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};

    cout << solution.isValidSudoku(board) << endl;
}