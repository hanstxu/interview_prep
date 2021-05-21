#include "../../test.h"
#include <climits>

int hammingWeight(uint32_t n) {
  int count = 0;
  while (n != 0) {
    n = n & (n - 1);
    ++count;
  }

  return count;
}

int main() {
  ASSERT_EQUALS(hammingWeight(0), 0);
  ASSERT_EQUALS(hammingWeight(4), 1);
  ASSERT_EQUALS(hammingWeight(7), 3);
  ASSERT_EQUALS(hammingWeight(1024), 1);
  ASSERT_EQUALS(hammingWeight(593), 4);
  ASSERT_EQUALS(hammingWeight(4294967293), 31);
  ASSERT_EQUALS(hammingWeight(4294967295), 32);
  ASSERT_EQUALS(hammingWeight(INT_MIN), 1);
  ASSERT_EQUALS(hammingWeight(INT_MAX), 31);
}
