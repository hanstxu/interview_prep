#include "../../test.h"
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
  if (height.size() < 2) {
    return 0;
  }

  int max_area = 0;
  int start = 0;
  int end = height.size() - 1;
  while (start < end) {
    int area = min(height[start], height[end]) * (end - start);
    max_area = max(max_area, area);

    if (height[start] < height[end]) {
      ++start;
    } else {
      --end;
    }
  }

  return max_area;
}

int main() {
  vector<int> input{};
  ASSERT_EQUALS(maxArea(input), 0);

  vector<int> input1{1};
  ASSERT_EQUALS(maxArea(input1), 0);

  vector<int> input2{2,2};
  ASSERT_EQUALS(maxArea(input2), 2);

  vector<int> input3{4,3,2,1,4};
  ASSERT_EQUALS(maxArea(input3), 16);

  vector<int> input4{1,2,1};
  ASSERT_EQUALS(maxArea(input4), 2);

  vector<int> input5{1,8,6,2,5,4,8,3,7};
  ASSERT_EQUALS(maxArea(input5), 49);

  vector<int> input6{1,3,8,8,3};
  ASSERT_EQUALS(maxArea(input6), 9);

  vector<int> input7{2,3,8,8,3,2};
  ASSERT_EQUALS(maxArea(input7), 10);

  vector<int> input8{1,3,2,5,25,24,5};
  ASSERT_EQUALS(maxArea(input8), 24);
}
