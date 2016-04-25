//
// Created by Neptune on 4/25/16.
//

/*
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<short> rows(9, 0), cols(rows), blocks(rows);

        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                auto c = board[i][j];

                if (c == '.') continue;

                auto bit = 1 << (c - '0');

                if (rows[i] & bit) return false;

                rows[i] |= bit;

                if (cols[j] & bit) return false;

                cols[j] |= bit;

                if (blocks[3 * (i / 3) + j / 3] & bit) return false;

                blocks[3 * (i / 3) + j / 3] |= bit;
            }

        return true;
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
    cout << Solution().isValidSudoku(board) << endl;
    return 0;
}

