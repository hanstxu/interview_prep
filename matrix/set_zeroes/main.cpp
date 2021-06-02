#include "../../test.h"
#include <vector>
using namespace std;

/**
 * Given a matrix, if an element is 0, set the entire row
 * to 0.
 */
void setZeroes(vector<vector<int>>& matrix) {
  bool is_row_zero = false;
  bool is_col_zero = false;

  for (int row = 0; row < matrix.size(); ++row) {
    if (matrix[row][0] == 0) {
      is_col_zero = true;
      break;
    }
  }

  for (int col = 0; col < matrix[0].size(); ++col) {
    if (matrix[0][col] == 0) {
      is_row_zero = true;
      break;
    }
  }

  for (int row = 1; row < matrix.size(); ++row) {
    for (int col = 1; col < matrix[row].size(); ++col) {
      int number = matrix[row][col];
      if (number == 0) {
        matrix[row][0] = 0;
        matrix[0][col] = 0;
      }
    }
  }

  for (int row = 1; row < matrix.size(); ++row) {
    for (int col = 1; col < matrix[row].size(); ++col) {
      if (matrix[row][0] == 0 || matrix[0][col] == 0) {
        matrix[row][col] = 0;
      }
    }
  }

  if (is_col_zero) {
    for (int row = 0; row < matrix.size(); ++row) {
      matrix[row][0] = 0;
    }
  }

  if (is_row_zero) {
    for (int col = 0; col < matrix[0].size(); ++col) {
      matrix[0][col] = 0;
    }
  }
}


int main() {
  vector<vector<int>> input1 = {{1,1,1},
                                {1,0,1},
                                {1,1,1}};
  vector<vector<int>> result1 = {{1,0,1},
                                 {0,0,0},
                                 {1,0,1}};
  setZeroes(input1);
  ASSERT_EQUALS(input1, result1);

  vector<vector<int>> input2 = {{0,1,2,0},
                                {3,4,5,2},
                                {1,3,1,5}};
  vector<vector<int>> result2 = {{0,0,0,0},
                                 {0,4,5,0},
                                 {0,3,1,0}};
  setZeroes(input2);
  ASSERT_EQUALS(input2, result2);

  vector<vector<int>> input3 = {{0,1,2,1},
                                {3,0,5,2},
                                {1,3,0,5}};
  vector<vector<int>> result3 = {{0,0,0,0},
                                 {0,0,0,0},
                                 {0,0,0,0}};
  setZeroes(input3);
  ASSERT_EQUALS(input3, result3);

  vector<vector<int>> input4 = {{0,1},
                                {3,0},
                                {1,3},
                                {7,4}};
  vector<vector<int>> result4 = {{0,0},
                                 {0,0},
                                 {0,0},
                                 {0,0}};
  setZeroes(input4);
  ASSERT_EQUALS(input4, result4);

  vector<vector<int>> input5 = {{1,2,3,4},
                                {5,6,0,0}};
  vector<vector<int>> result5 = {{1,2,0,0},
                                 {0,0,0,0}};
  setZeroes(input5);
  ASSERT_EQUALS(input5, result5);
}
