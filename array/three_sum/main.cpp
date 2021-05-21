#include "../../test.h"
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& numbers) {
  vector<vector<int>> result;
  if (numbers.size() < 3) {
    return result;
  }

  sort(numbers.begin(), numbers.end());

  for (int i = 0; i < numbers.size() - 2; i++) {
    if (numbers[i] > 0) {
      break;
    }

    if (i > 0 && numbers[i] == numbers[i - 1]) {
      continue;
    }

    int target = 0 - numbers[i];
    int start = i + 1;
    int end = numbers.size()- 1;

    while (start < end) {
      if (numbers[start] + numbers[end] < target) {
        ++start;

      } else if (numbers[start] + numbers[end] > target) {
        --end;

      } else {
        vector<int> sum = vector<int>{-target, numbers[start], numbers[end]};
        result.push_back(sum);

        while (start < end && numbers[start] == numbers[start + 1]) ++start;
        while (start < end && numbers[end] == numbers[end - 1]) --end;

        ++start;
        --end;
      }
    }
  }

  return result;
}

int main() {
  vector<int> input{};
  ASSERT_TRUE(threeSum(input).empty());

  vector<int> input1{1};
  ASSERT_TRUE(threeSum(input1).empty());

  vector<int> input2{4,2,1,3};
  ASSERT_TRUE(threeSum(input2).empty());

  vector<int> input3{-1,0,1,2,-1,-4};
  ASSERT_EQUALS(threeSum(input3).size(), 2);
  ASSERT_EQUALS(threeSum(input3)[0], (vector<int>{-1,-1,2}));
  ASSERT_EQUALS(threeSum(input3)[1], (vector<int>{-1,0,1}));

  vector<int> input4{-3,1,1,2,4,4,6,-7,0,0,0,5,7,3,3,3,10};
  ASSERT_EQUALS(threeSum(input4).size(), 8);
  ASSERT_EQUALS(threeSum(input4)[0], (vector<int>{-7,-3,10}));
  ASSERT_EQUALS(threeSum(input4)[1], (vector<int>{-7,0,7}));
  ASSERT_EQUALS(threeSum(input4)[2], (vector<int>{-7,1,6}));
  ASSERT_EQUALS(threeSum(input4)[3], (vector<int>{-7,2,5}));
  ASSERT_EQUALS(threeSum(input4)[4], (vector<int>{-7,3,4}));
  ASSERT_EQUALS(threeSum(input4)[5], (vector<int>{-3,0,3}));
  ASSERT_EQUALS(threeSum(input4)[6], (vector<int>{-3,1,2}));
  ASSERT_EQUALS(threeSum(input4)[7], (vector<int>{0,0,0}));
}
