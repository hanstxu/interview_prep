#include "../../test.h"
using namespace std;

/**
 * Given a 32-bit unsigned integer, return the unsigned integer
 * when the bits are reversed.
 */
uint32_t reverseBits(uint32_t n) {
  n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
  n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
  n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
  n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
  return ((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16);
}

int main() {
  ASSERT_EQUALS(reverseBits(0), 0);
  ASSERT_EQUALS(reverseBits(1), 2147483648);
  ASSERT_EQUALS(reverseBits(2147483648), 1);
  ASSERT_EQUALS(reverseBits(1024), 2097152);
  ASSERT_EQUALS(reverseBits(2097152), 1024);
  ASSERT_EQUALS(reverseBits(43261596), 964176192);
  ASSERT_EQUALS(reverseBits(4294967293), 3221225471);
}
