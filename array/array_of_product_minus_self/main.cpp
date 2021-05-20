#include "../../test.h"
#include <vector>
using namespace std;

/**
 * Given a list of numbers, return an array where each index
 * contains the product all the numbers in the array minus
 * the number at that index.
 */
vector<int> getProductArray(vector<int>& numbers) {
  vector<int> result(numbers.size(), 1);
  int product = 1;
  for (int i = 0; i < numbers.size(); i++) {
    result[i] = result[i] * product;
    product *= numbers[i];
  }

  product = 1;
  for (int i = numbers.size() - 1; i >= 0; i--) {
    result[i] = result[i] * product;
    product *= numbers[i];
  }

  return result;
}


int main() {
  vector<int> input;
  vector<int> expected_result;
  ASSERT_EQUALS(getProductArray(input), expected_result);

  vector<int> input1{1};
  vector<int> expected_result1{1};
  ASSERT_EQUALS(getProductArray(input1), expected_result1);

  vector<int> input2{1,2,3,4};
  vector<int> expected_result2{24,12,8,6};
  ASSERT_EQUALS(getProductArray(input2), expected_result2);

  vector<int> input3{-1,1,0,-3,3};
  vector<int> expected_result3{0,0,9,0,0};
  ASSERT_EQUALS(getProductArray(input3), expected_result3);
}
