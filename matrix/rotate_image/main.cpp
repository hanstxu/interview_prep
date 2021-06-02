#include "../../test.h"
#include <vector>
using namespace std;

/**
 * Given a 2d n by n matrix, rotate the matrix
 * by 90 degrees.
 */
void rotate(vector<vector<int>>& matrix) {
  int n = matrix.size();
  int m = n - 1;

  for (int row = 0; row < (n + 1) / 2; ++row) {
    for (int col = 0; col < n / 2; ++col) {
      int temp = matrix[row][col];

      matrix[row][col] = matrix[m - col][row];
      matrix[m - col][row] = matrix[m - row][m - col];
      matrix[m - row][m - col] = matrix[col][m - row];
      matrix[col][m - row] = temp;
    }
  }
}

int main() {
  vector<vector<int>> input1 = {{1,2,3},
                                {4,5,6},
                                {7,8,9}};
  vector<vector<int>> result1 = {{7,4,1},
                                 {8,5,2},
                                 {9,6,3}};
  rotate(input1);
  ASSERT_EQUALS(input1, result1);

  vector<vector<int>> input2 = {{1,2,3,4},
                                {5,6,7,8},
                                {9,10,11,12},
                                {13,14,15,16}};
  vector<vector<int>> result2 = {{13,9,5,1},
                                 {14,10,6,2},
                                 {15,11,7,3},
                                 {16,12,8,4}};
  rotate(input2);
  ASSERT_EQUALS(input2, result2);

  vector<vector<int>> input3 = {{1,2,3,4,5},
                                {6,7,8,9,10},
                                {11,12,13,14,15},
                                {16,17,18,19,20},
                                {21,22,23,24,25}};
  vector<vector<int>> result3 = {{21,16,11,6,1},
                                 {22,17,12,7,2},
                                 {23,18,13,8,3},
                                 {24,19,14,9,4},
                                 {25,20,15,10,5}};
  rotate(input3);
  ASSERT_EQUALS(input3, result3);
}
