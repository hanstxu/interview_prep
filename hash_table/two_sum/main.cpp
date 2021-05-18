#include "../../test.h"
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * Given an array of integers and a target sum, return the
 * indices of the two numbers such that they add to the
 * target.
 */
vector<int> twoSum(vector<int>& numbers, int target) {
  unordered_map<int, int> seen;
  for (int i = 0; i < numbers.size(); i++) {
    int number = numbers[i];
    if (seen.count(target - number) == 1) {
      vector<int> result{seen[target - number], i};
      return result;
    } else {
      seen[number] = i;
    }
  }
  vector<int> result;
  return result;
}

int main() {
  vector<int> base_case{1,3,5};

  vector<int> test_case1{1,2};
  ASSERT_EQUALS(twoSum(base_case, 8), test_case1);

  vector<int> test_case2{0,1};
  ASSERT_EQUALS(twoSum(base_case, 4), test_case2);

  vector<int> test_case3{0,2};
  ASSERT_EQUALS(twoSum(base_case, 6), test_case3);
}