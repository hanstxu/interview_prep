#include "../../test.h"
#include <vector>
using namespace std;

/**
 * Given an integer n, return the number of bits in each
 * number in the counting sequence up to n in an array.
 */
vector<int> countBits(int n) {
  vector<int> result(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    result[i] = result[i & (i - 1)] + 1;
  }
  return result;
}

int main() {
  ASSERT_EQUALS(countBits(0), (vector<int>{0}));
  ASSERT_EQUALS(countBits(1), (vector<int>{0,1}));
  ASSERT_EQUALS(countBits(2), (vector<int>{0,1,1}));
  ASSERT_EQUALS(countBits(5), (vector<int>{0,1,1,2,1,2}));
  ASSERT_EQUALS(countBits(16), (vector<int>{0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1}));
}
