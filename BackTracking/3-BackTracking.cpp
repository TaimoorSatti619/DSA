#include <iostream>
#include <vector>
using namespace std;


// QUESTION  =>  Soduku Solver ------------------


bool isSafe(vector<vector<int>> &board, int row, int col, int val) {

  for (int i = 0; i < 9; i++) {

    // row check
    if (board[row][i] == val) {
      return false;
    }

    // col check
    if (board[i][col] == val) {
      return false;
    }

    // 3*3 matrix check
    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
      return false;
    }
  }

  return true;
}

bool solve(vector<vector<int>> &board) {

  int n = board[0].size();

  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {

      // check empty space
      if (board[row][col] == 0) {
        for (int i = 1; i <= 9; i++) {

          if (isSafe(board, row, col, i)) {
            board[row][col] = i;

            // recursive call
            bool ageyPossible = solve(board);
            if (ageyPossible) {
              return true;
            } else {

              // backtracking
              board[row][col] = 0;
            }
          }
        }
        return false;
      }
    }
  }
  return true;
}

void solveSudoku(vector<vector<int>> &board) { solve(board); }
