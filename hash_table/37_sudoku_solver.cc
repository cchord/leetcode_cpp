//
// Created by Neptune on 4/25/16.
//

/*
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * Empty cells are indicated by the character '.'.
 * You may assume that there will be only one unique solution.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    void solveSudoku(vector <vector<char>> &board) {
        vector<vector<int>> memTable{
            vector<int>(9, 0), // rows
            vector<int>(9, 0), // cols
            vector<int>(9, 0) // blocks
        };

        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                auto c = board[i][j];

                if (c == '.') continue;

                auto bit = 1 << (c - '0');
                memTable[0][i] |= bit;
                memTable[1][j] |= bit;
                memTable[2][3 * (i / 3) + j / 3] |= bit;
            }

        solve(board, memTable, 0, 0);
    }

    // back tracking
    bool solve(vector<vector<char>> &board, vector<vector<int>> &memTable, int row, int col) {
        if (col >= 9) {
            col = 0;
            row ++;
        }

        if (row >= 9)
            return true;

        char &c = board[row][col];

        if (c != '.')
            return solve(board, memTable, row, col + 1);

        for (char d = '1'; d <= '9'; ++d) {
            auto bit = 1 << (d - '0');

            if (!(bit & memTable[0][row]) && !(bit & memTable[1][col]) && !(bit & memTable[2][3 * (row / 3) + col / 3])) {
                c = d;
                memTable[0][row] |= bit;
                memTable[1][col] |= bit;
                memTable[2][3 * (row / 3) + col / 3] |= bit;

                if (solve(board, memTable, row, col + 1))
                    return true;

                c = '.';
                memTable[0][row] &= ~bit;
                memTable[1][col] &= ~bit;
                memTable[2][3 * (row / 3) + col / 3] &= ~bit;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    Solution().solveSudoku(board);

    for (auto &row : board) {
        for (auto &n : row)
            cout << n << " ";

        cout << endl;
    }

    return 0;
}
