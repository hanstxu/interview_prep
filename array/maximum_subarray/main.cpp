#include "../../test.h"
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Given an array of numbers, return the largest sum
 * that can be obtained from a contiguous subarray.
 */
int maxSubArray(vector<int>& numbers) {
  if (numbers.empty()) {
    return 0;
  }

  int max_sum = numbers[0];
  int sum = 0;
  for (auto number: numbers) {
    sum += number;
    max_sum = max(max_sum, sum);
    if (sum < 0) {
      sum = 0;
    }
  }
  return max_sum;
}

int main() {
  vector<int> input;
  ASSERT_EQUALS(maxSubArray(input), 0);

  vector<int> input1{1};
  ASSERT_EQUALS(maxSubArray(input1), 1);

  vector<int> input2{-2,1,-3,4,-1,2,1,-5,4};
  ASSERT_EQUALS(maxSubArray(input2), 6);

  vector<int> input3{5,4,-1,7,8};
  ASSERT_EQUALS(maxSubArray(input3), 23);

  vector<int> input4{-3,-1,-4,-5};
  ASSERT_EQUALS(maxSubArray(input4), -1);
}
