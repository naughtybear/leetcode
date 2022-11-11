// Runtime: 10 ms, faster than 95.35% of C++ online submissions for Sudoku Solver.
// Memory Usage: 6.5 MB, less than 15.69% of C++ online submissions for Sudoku Solver.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void jumpToEmpty(vector<vector<char>>& board, int& i, int& j) {
        while (board[i][j] != '.')
        {
            if (j == 8){
                j = 0;
                i ++;
            }
            else
                j++;
            if(i == 9)
                return;
        }
    }
    bool searchSudoku(vector<vector<char>>& board, int row[][10], int column[][10], int block[][10], int i, int j, int value) {

        if (row[i][value] == 0 && column[j][value] == 0 && block[(i / 3) * 3 + j / 3][value] == 0) {
            board[i][j] = value + '0';
            row[i][value] = 1;
            column[j][value] = 1;
            block[(i / 3) * 3 + j / 3][value]  = 1;
            int previos_i = i, previous_j = j;
            if (j == 8) {
                if (i == 8)
                    return true;
                else {
                    i++;
                    j = 0;
                    jumpToEmpty(board, i, j);
                    if (i == 9)
                        return true;
                    for (int idx = 1; idx <=9; idx++){
                        if(searchSudoku(board, row, column, block, i, j, idx) == true)
                            return true;
                    }
                    board[previos_i][previous_j] = '.';
                    row[previos_i][value] = 0;
                    column[previous_j][value] = 0;
                    block[(previos_i / 3) * 3 + previous_j / 3][value]  = 0;
                    return false;
                }
            }
            else{
                j++;
                jumpToEmpty(board, i, j);
                if (i == 9)
                    return true;
                for (int idx = 1; idx <= 9; idx++){
                    if(searchSudoku(board, row, column, block, i, j, idx) == true)
                        return true;
                }
                board[previos_i][previous_j] = '.';
                row[previos_i][value] = 0;
                column[previous_j][value] = 0;
                block[(previos_i / 3) * 3 + previous_j / 3][value]  = 0;
                return false;
            }
        }
        else 
            return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int row[9][10], column[9][10], block[9][10];
        stack<vector<int>> memory; // store as <i, j, number>

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 10; j++){
                row[i][j] = 0;
                column[i][j] = 0;
                block[i][j] = 0;
            }
        }

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    row[i][board[i][j] - '0'] = 1;
                    column[j][board[i][j] - '0'] = 1;
                    block[(i / 3) * 3 + j / 3][board[i][j] - '0'] = 1;
                }
            }
        }
        int i = 0, j = 0;
        jumpToEmpty(board, i, j);
        for (int idx = 1; idx <= 9; idx++){
            if(searchSudoku(board, row, column, block, i, j, idx) == true)
                break;
        }
        // cout << 1 << endl;
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

    solution.solveSudoku(board);
}