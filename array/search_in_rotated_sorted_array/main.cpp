#include "../../test.h"
#include <vector>
using namespace std;

int getNumber(vector<int>& numbers, int index);

/**
 * Given a rotated sorted array and a target, find if the target
 * exists in the array in O(log n) time.
 * A rotated sorted array is something like the following:
 *    [4,5,6,1,2,3]
 */
int search(vector<int>& numbers, int target) {
  if (numbers.empty()) {
    return -1;
  }

  int start = 0;
  int end = numbers.size() * 2 - 1;

  while (start != end) {
    int mid = (start + end) / 2;
    if (getNumber(numbers, mid) == target) {
      return mid % numbers.size();

    } else if (getNumber(numbers, start) <= getNumber(numbers, mid)) {
      if (target >= getNumber(numbers, start) && target < getNumber(numbers, mid)) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }

    } else {
      if (target > getNumber(numbers, mid) && target <= getNumber(numbers, end)) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }

    }
  }

  return (getNumber(numbers, start) == target) ? start % numbers.size() : -1;
}

int getNumber(vector<int>& numbers, int index) {
  return numbers[index % numbers.size()];
}

int main() {
  vector<int> input{};
  ASSERT_EQUALS(search(input, 1), -1);

  vector<int> input1{1};
  ASSERT_EQUALS(search(input1, 1), 0);

  vector<int> input2{1};
  ASSERT_EQUALS(search(input2, 0), -1);

  vector<int> input3{1,2};
  ASSERT_EQUALS(search(input3, 1), 0);

  vector<int> input4{2,1};
  ASSERT_EQUALS(search(input4, 1), 1);

  vector<int> input5{4,5,6,7,0,1,2};
  ASSERT_EQUALS(search(input5, 0), 4);

  vector<int> input6{4,5,6,7,0,1,2};
  ASSERT_EQUALS(search(input6, 1), 5);

  vector<int> input7{4,5,6,7,0,1,2};
  ASSERT_EQUALS(search(input7, 3), -1);
}
