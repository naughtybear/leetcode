// Runtime: 43 ms, faster than 36.64% of C++ online submissions for Valid Sudoku.
// Memory Usage: 17.8 MB, less than 99.84% of C++ online submissions for Valid Sudoku.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.')
                    continue;
                for (int k = 0; k < 9; k++) {
                    if (board[i][k] == board[i][j] && k != j) return false;
                    if (board[k][j] == board[i][j] && k != i) return false;
                }
                int x = i - i % 3, y = j - j % 3;
                for (int k = 0; k < 3; k++){
                    for (int l = 0; l < 3; l++)
                        if (board[x + k][y + l] == board[i][j] && (x + k != i || y + l !=j)) return false;
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
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};

    cout << solution.isValidSudoku(board) << endl;
}