#include "../../test.h"
#include <vector>
using namespace std;

/**
 * Given an array of numbers containing the counting sequence from
 * [0, n] except for a missing number, return that missing number.
 */
int missingNumberXor(vector<int>& numbers) {
  int missing_number = 0;
  for (int i = 0; i <= numbers.size(); ++i) {
    missing_number ^= i;
  }

  for (auto number: numbers) {
    missing_number ^= number;
  }

  return missing_number;
}

int missingNumber(vector<int>& numbers) {
  int n = numbers.size();
  int expected_sum = (0 + n) * (n + 1) / 2;

  int missing_number = expected_sum;
  for (auto number: numbers) {
    missing_number -= number;
  }

  return missing_number;
}

int main() {
  vector<int> input1{0,3,1};
  ASSERT_EQUALS(missingNumberXor(input1), 2);
  ASSERT_EQUALS(missingNumber(input1), 2);

  vector<int> input2{0,1};
  ASSERT_EQUALS(missingNumberXor(input2), 2);
  ASSERT_EQUALS(missingNumber(input2), 2);

  vector<int> input3{9,6,4,2,3,5,7,0,1};
  ASSERT_EQUALS(missingNumberXor(input3), 8);
  ASSERT_EQUALS(missingNumber(input3), 8);

  vector<int> input4{0};
  ASSERT_EQUALS(missingNumberXor(input4), 1);
  ASSERT_EQUALS(missingNumber(input4), 1);
}
