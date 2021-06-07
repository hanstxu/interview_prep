#include "../../test.h"
using namespace std;

/**
 * While climbing a staircase, you can either only climb 1 or 2 steps.
 * Given that it takes n steps to reach the top, how many distinct ways
 * can you climb to the top.
 */
int climbStairs(int n) {
  if (n == 0) {
    return 0;
  }

  if (n == 1) {
    return 1;
  }

  int one_below_top = 1;
  int top = 2;
  for (int i = 2; i < n; ++i) {
    int new_top = one_below_top + top;
    one_below_top = top;
    top = new_top;
  }

  return top;
}

int main() {
  ASSERT_EQUALS(climbStairs(0), 0);
  ASSERT_EQUALS(climbStairs(1), 1);
  ASSERT_EQUALS(climbStairs(2), 2);
  ASSERT_EQUALS(climbStairs(3), 3);
  ASSERT_EQUALS(climbStairs(4), 5);
  ASSERT_EQUALS(climbStairs(5), 8);
}