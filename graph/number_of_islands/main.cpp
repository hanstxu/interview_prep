#include "../../test.h"
#include <vector>
using namespace std;

/**
 * Given a 2D binary grid where '1' represents land and '0'
 * represents water, return the number of islands.
 */
void dfs(vector<vector<char>>& grid, int i, int j) {
  grid[i][j] = '0';

  if (i > 0 && grid[i - 1][j] == '1') {
    dfs(grid, i - 1, j);
  }

  if (j > 0 && grid[i][j - 1] == '1') {
    dfs(grid, i, j - 1);
  }

  if (i < grid.size() - 1 && grid[i + 1][j] == '1') {
    dfs(grid, i + 1, j);
  }

  if (j < grid[0].size() - 1 && grid[i][j + 1] == '1') {
    dfs(grid, i, j + 1);
  }
}

int numIslands(vector<vector<char>>& grid) {
  int count = 0;
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[0].size(); ++j) {
      if (grid[i][j] == '1') {
        dfs(grid, i, j);
        count++;
      }
    }
  }

  return count;
}

int main() {
  vector<vector<char>> empty_grid;
  ASSERT_EQUALS(numIslands(empty_grid), 0);

  vector<vector<char>> grid_1 = {{'1','1','1','1','0'},
                                 {'1','1','0','1','0'},
                                 {'1','1','0','0','0'},
                                 {'1','0','0','0','0'}};
  ASSERT_EQUALS(numIslands(grid_1), 1);

  vector<vector<char>> grid_2 = {{'1','1','0','0','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','1','0','0'},
                                 {'0','0','0','1','1'}};
  ASSERT_EQUALS(numIslands(grid_2), 3);

  vector<vector<char>> grid_3 = {{'1','0','1','0','1'},
                                 {'0','1','0','1','0'},
                                 {'1','0','1','0','1'},
                                 {'0','1','0','1','0'}};
  ASSERT_EQUALS(numIslands(grid_3), 10);
}
