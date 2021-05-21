#include "../../test.h"
using namespace std;

/**
 * Given two numbers, obtain the sum using only
 * bitwise operations.
 */
int getSum(int a, int b) {
  int sum = a;
  while (b != 0) {
    sum = a ^ b;
    b = (unsigned int) (a & b) << 1;
    a = sum;
  }

  return sum;
}

int main() {
  ASSERT_EQUALS(getSum(1,2), 3);
  ASSERT_EQUALS(getSum(2,3), 5);
  ASSERT_EQUALS(getSum(7,0), 7);
  ASSERT_EQUALS(getSum(0,7), 7);
  ASSERT_EQUALS(getSum(1,-1), 0);
  ASSERT_EQUALS(getSum(-1,1), 0);
  ASSERT_EQUALS(getSum(-3,9), 6);
  ASSERT_EQUALS(getSum(8,-12), -4);
}
