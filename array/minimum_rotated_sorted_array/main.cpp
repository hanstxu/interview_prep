#include "../../test.h"
#include <vector>
using namespace std;

int getNumber(vector<int>& numbers, int index);

/**
 * Given a rotated sorted array, find the minimum in O(log n) time.
 * A rotated sorted array is something like the following:
 *    [4,5,6,1,2,3]
 */
int findMin(vector<int>& numbers) {
  if (numbers.empty()) {
    return 0;
  }

  int start = 0;
  int end = numbers.size() * 2;

  int first_mid_index = (start + end) / 2 - 1;
  int second_mid_index = (start + end) / 2;

  while (getNumber(numbers, first_mid_index) < getNumber(numbers, second_mid_index)) {
    if (getNumber(numbers, first_mid_index) < getNumber(numbers, start)) {
      end = first_mid_index;
    } else {
      start = second_mid_index;
    }

    if (end - start == 1) {
      first_mid_index = start;
      second_mid_index = end;
    } else {
      first_mid_index = (start + end) / 2 - 1;
      second_mid_index = (start + end) / 2;
    }
  }

  return getNumber(numbers, second_mid_index);
}

int getNumber(vector<int>& numbers, int index) {
  return numbers[index % numbers.size()];
}

int main() {
  vector<int> input{};
  ASSERT_EQUALS(findMin(input), 0);

  vector<int> input1{1};
  ASSERT_EQUALS(findMin(input1), 1);

  vector<int> input2{1,2};
  ASSERT_EQUALS(findMin(input2), 1);

  vector<int> input3{2,1};
  ASSERT_EQUALS(findMin(input3), 1);

  vector<int> input4{3,4,5,1,2};
  ASSERT_EQUALS(findMin(input4), 1);

  vector<int> input5{4,5,6,7,0,1,2};
  ASSERT_EQUALS(findMin(input5), 0);

  vector<int> input6{11,13,15,17};
  ASSERT_EQUALS(findMin(input6), 11);

  vector<int> input7{1,2,3,4,5,6};
  ASSERT_EQUALS(findMin(input7), 1);

  vector<int> input8{2,3,4,5,6,1};
  ASSERT_EQUALS(findMin(input8), 1);

  vector<int> input9{3,4,5,6,1,2};
  ASSERT_EQUALS(findMin(input9), 1);

  vector<int> input10{4,5,6,1,2,3};
  ASSERT_EQUALS(findMin(input10), 1);

  vector<int> input11{5,6,1,2,3,4};
  ASSERT_EQUALS(findMin(input11), 1);

  vector<int> input12{6,1,2,3,4,5};
  ASSERT_EQUALS(findMin(input12), 1);
}
