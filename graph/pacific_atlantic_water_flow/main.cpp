#include "../../test.h"
#include <vector>
#include <queue>
using namespace std;

/**
 * A rectangular island borders the Pacific Ocean on its top and left
 * edges and borders the Atlantic Ocean on its bottom and right edges.
 *
 * It is represented by a 2d m by n grid with heights above sea level
 * represented at each cell. Rain water will flow to adjacent cells
 * that are less than or equal to the current cell's height.
 *
 * Return a list of 2D grid coordinates whose rain water flows to
 * both oceans.
 */
typedef pair<int, int> Coordinate;

int directions[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

void bfs(vector<vector<int>>& heights,
         queue<Coordinate>& coordinate_queue,
         vector<vector<bool>>& visited) {

  int n = heights.size() - 1;
  int m = heights[0].size() - 1;

  while (!coordinate_queue.empty()) {
    Coordinate coordinate = coordinate_queue.front();
    coordinate_queue.pop();

    int x = coordinate.first;
    int y = coordinate.second;

    for (auto direction: directions) {
      int i = x + direction[0];
      int j = y + direction[1];

      if (i < 0 || j < 0 || i > n || j > m) {
        continue;
      }

      if (visited[i][j]) {
        continue;
      }

      if (heights[x][y] > heights[i][j]) {
        continue;
      }

      visited[i][j] = true;
      coordinate_queue.push({i, j});
    }
  }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
  if (heights.empty()) {
    return vector<vector<int>>();
  }

  vector<vector<bool>> pacific(heights.size(),
                               vector<bool>(heights[0].size(), false));

  vector<vector<bool>> atlantic(heights.size(),
                                vector<bool>(heights[0].size(), false));

  queue<Coordinate> pacific_queue;
  queue<Coordinate> atlantic_queue;

  int n = heights.size();
  int m = heights[0].size();
  for (int i = 0; i < n; ++i) {
    pacific[i][0] = true;
    atlantic[i][m - 1] = true;

    pacific_queue.push({i, 0});
    atlantic_queue.push({i, m - 1});
  }

  for (int i = 0; i < m; ++i) {
    pacific[0][i] = true;
    atlantic[n - 1][i] = true;

    pacific_queue.push({0, i});
    atlantic_queue.push({n - 1, i});
  }

  bfs(heights, pacific_queue, pacific);
  bfs(heights, atlantic_queue, atlantic);

  vector<vector<int>> coordinates;
  for (int i = 0; i < heights.size(); ++i) {
    for (int j = 0; j < heights[0].size(); ++j) {
      if (pacific[i][j] && atlantic[i][j]) {
        coordinates.push_back(vector<int>{i, j});
      }
    }
  }

  return coordinates;
}

int main() {
  vector<vector<int>> no_island;
  ASSERT_EQUALS(pacificAtlantic(no_island), vector<vector<int>>());

  vector<vector<int>> island_1 = {{2,1},
                                  {1,2}};
  ASSERT_EQUALS(pacificAtlantic(island_1),
                (vector<vector<int>>{{0,0},{0,1},
                                     {1,0},{1,1}}));

  vector<vector<int>> island_2 = {{1,2,2,3,5},
                                  {3,2,3,4,4},
                                  {2,4,5,3,1},
                                  {6,7,1,4,5},
                                  {5,1,1,2,4}};
  ASSERT_EQUALS(pacificAtlantic(island_2),
                (vector<vector<int>>{{0,4},{1,3},{1,4},
                                     {2,2},{3,0},{3,1},
                                     {4,0}}));

  vector<vector<int>> island_3 = {{1,1},
                                  {1,1},
                                  {1,1}};
  ASSERT_EQUALS(pacificAtlantic(island_3),
                (vector<vector<int>>{{0,0},{0,1},{1,0},
                                     {1,1},{2,0},{2,1}}));
}
