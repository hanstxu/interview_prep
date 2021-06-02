#include "../../test.h"
#include <vector>
using namespace std;

/**
 * Given a matrix, return all elements of the matrix
 * in spiral order.
 */
enum Direction{right, down, left, up};

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  vector<int> result;

  Direction direction = Direction::right;

  int left_bound = 0;
  int right_bound = matrix[0].size() - 1;
  int top_bound = 1;
  int bottom_bound = matrix.size() - 1;

  int row = 0;
  int col = 0;

  for (int i = 0; i < matrix.size() * matrix[0].size(); ++i) {
    result.push_back(matrix[row][col]);

    switch (direction) {
      case Direction::right:
        if (col == right_bound) {
          --right_bound;
          ++row;
          direction = Direction::down;
        } else {
          ++col;
        }
        break;

      case Direction::down:
        if (row == bottom_bound) {
          --bottom_bound;
          --col;
          direction = Direction::left;
        } else {
          ++row;
        }
        break;

      case Direction::left:
        if (col == left_bound) {
          ++left_bound;
          --row;
          direction = Direction::up;
        } else {
          --col;
        }
        break;

      case Direction::up:
        if (row == top_bound) {
          ++top_bound;
          ++col;
          direction = Direction::right;
        } else {
          --row;
        }
        break;
    }
  }

  return result;
}

int main() {
  vector<vector<int>> input1 = {{1,2,3,4,5,6,7,8,9}};
  vector<int> result1 = {1,2,3,4,5,6,7,8,9};
  ASSERT_EQUALS(spiralOrder(input1), result1);

  vector<vector<int>> input2 = {{1},
                                {2},
                                {3},
                                {4},
                                {5},
                                {6},
                                {7},
                                {8},
                                {9}};
  vector<int> result2 = {1,2,3,4,5,6,7,8,9};
  ASSERT_EQUALS(spiralOrder(input2), result2);

  vector<vector<int>> input3 = {{1,2,3},
                                {4,5,6},
                                {7,8,9}};
  vector<int> result3 = {1,2,3,6,9,8,7,4,5};
  ASSERT_EQUALS(spiralOrder(input3), result3);

  vector<vector<int>> input4 = {{1,2,3,4},
                                {5,6,7,8},
                                {9,10,11,12}};
  vector<int> result4 = {1,2,3,4,8,12,11,10,9,5,6,7};
  ASSERT_EQUALS(spiralOrder(input4), result4);
}
