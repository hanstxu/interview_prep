#include "../../test.h"
#include <vector>
#include <algorithm>
using namespace std;

// start and end are inclusive indices
int maxProductHelper(vector<int>& numbers, int start, int end);
int maxProductEvenNegatives(vector<int>& numbers, int start, int end);
int maxProductSingleNegative(vector<int>& numbers, int start, int end);
int maxProductOddNegatives(vector<int>& numbers, int start, int end);


// Algorithm:
//    1. Section each array off by 0's as a delimiter
//    2. For each section, determine whether there is an odd number of negatives
//    3. If there is an even number of negatives, get the total product
//    4. If there is an odd number of negatives, prune the smaller ends
/**
 * Given an array of numbers, return the largest product
 * that can be provided by a contiguous subarray.
 */
int maxProduct(vector<int>& numbers) {
  if (numbers.empty()) {
    return 0;
  }

  int max_product = numbers[0];
  int start = 0;
  for (int i = 0; i < numbers.size(); i++) {
    if (numbers[i] == 0) {
      if (max_product < 0) {
        max_product = 0;
      }

      int end = i - 1;
      if (start <= end) {
        int product = maxProductHelper(numbers, start, end);
        max_product = max(max_product, product);
      }

      start = i + 1;
    }
  }

  int end = numbers.size() - 1;
  if (start <= end) {
    int product = maxProductHelper(numbers, start, end);
    max_product = max(max_product, product);
  }

  return max_product;
}

int maxProductHelper(vector<int>& numbers, int start, int end) {
  if (start == end) {
    return numbers[start];
  }

  int negative_count = 0;
  for (int i = start; i <= end; i++) {
    if (numbers[i] < 0) {
      ++negative_count;
    }
  }

  if (negative_count == 1) {
    return maxProductSingleNegative(numbers, start, end);

  } else if (negative_count % 2 == 0) {
    return maxProductEvenNegatives(numbers, start, end);
  }

  return maxProductOddNegatives(numbers, start, end);
}

int maxProductEvenNegatives(vector<int>& numbers, int start, int end) {
  int product = 1;
  for (int i = start; i <= end; i++) {
    product *= numbers[i];
  }
  return product;
}

int maxProductSingleNegative(vector<int>& numbers, int start, int end) {
  int left_product = 1;
  int i = start;
  while (numbers[i] > 0) {
    left_product *= numbers[i];
    ++i;
  }

  int right_product = 1;
  i = end;
  while (numbers[i] > 0) {
    right_product *= numbers[i];
    --i;
  }

  return left_product > right_product ? left_product : right_product;
}

int maxProductOddNegatives(vector<int>& numbers, int start, int end) {
  int left_product = 1;
  for (int i = start; i <= end; ++i) {
    left_product *= numbers[i];
    if (numbers[i] < 0) {
      break;
    }
  }

  int right_product = 1;
  for (int i = end; i >= start; --i) {
    right_product *= numbers[i];
    if (numbers[i] < 0) {
      break;
    }
  }

  int product = 1;
  for (int i = start; i <= end; i++) {
    product *= numbers[i];
  }

  int divisor = (left_product > right_product) ? left_product : right_product;
  return product / divisor;
}

int main() {
  vector<int> input{};
  ASSERT_EQUALS(maxProduct(input), 0);

  vector<int> input1{1};
  ASSERT_EQUALS(maxProduct(input1), 1);

  vector<int> input2{-1};
  ASSERT_EQUALS(maxProduct(input2), -1);

  vector<int> input3{2,3,-2,4};
  ASSERT_EQUALS(maxProduct(input3), 6);

  vector<int> input4{-2,0,-1};
  ASSERT_EQUALS(maxProduct(input4), 0);

  vector<int> input5{1,2,3,4};
  ASSERT_EQUALS(maxProduct(input5), 24);

  vector<int> input6{-1,-2,-3,-4};
  ASSERT_EQUALS(maxProduct(input6), 24);

  vector<int> input7{-1,-2,-3,-4,-5};
  ASSERT_EQUALS(maxProduct(input7), 120);

  vector<int> input8{1,-2,-3,-4,5};
  ASSERT_EQUALS(maxProduct(input8), 60);

  vector<int> input9{0,-1,-4,0,-3,-5,-4,0,12};
  ASSERT_EQUALS(maxProduct(input9), 20);
}