#include <iostream>
#include <vector>
using namespace std;

/// Question   =>  Rat in a Maze problem

bool isSafe(int i, int j, vector<vector<bool>> &visited,
            vector<vector<int>> &arr, int n) {

  if ((i >= 0 && i < n) && (j >= 0 && j < n) && (visited[i][j] != 1) &&
      (arr[i][j] == 1)) {
    return true;
  } else {
    return false;
  }
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans,
           vector<vector<bool>> &visited, string path) {

  // base case
  if (x == n - 1 && y == n - 1) {
    ans.push_back(path);
    return;
  }

  // 4 Movement
  // D , L , R, U

  visited[x][y] = 1;

  // Down
  // Down
  if (isSafe(x + 1, y, visited, arr, n)) {
    solve(x + 1, y, arr, n, ans, visited, path + 'D');
  }

  // Left
  if (isSafe(x, y - 1, visited, arr, n)) {
    solve(x, y - 1, arr, n, ans, visited, path + 'L');
  }

  // Right
  if (isSafe(x, y + 1, visited, arr, n)) {
    solve(x, y + 1, arr, n, ans, visited, path + 'R');
  }

  // Down
  if (isSafe(x - 1, y, visited, arr, n)) {
    solve(x - 1, y, arr, n, ans, visited, path + 'U');
  }

  visited[x][y] = 0;
}

vector<string> ratInMaze(vector<vector<int>> &maze) {

  int n = maze.size();

  vector<string> ans;
  vector<vector<bool>> visited(n, vector<bool>(n, 0));
  string path = "";

  if (maze[0][0] == 0) {
    return ans;
  }

  solve(0, 0, maze, n, ans, visited, path);
  return ans;
}