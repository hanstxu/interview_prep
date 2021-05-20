#include "../../test.h"
using namespace std;

void handlePositiveNumber(int& number, int& first_pos, int& second_pos, int& third_pos);
void handleNegativeNumber(int& number,
                          int& first_neg,
                          int& second_neg,
                          int& third_neg,
                          int& first_abs_neg,
                          int& second_abs_neg);

/**
 * Given an array of integers, return the maximum product that
 * can be obtained by three numbers in the array.
 */
int maximumProduct(vector<int>& numbers) {
  if (numbers.size() <= 2) {
    return 0;
  }

  bool seen_pos = false;
  bool seen_neg = false;
  bool seen_zero = false;

  int first_pos = 0;
  int second_pos = 0;
  int third_pos = 0;

  int first_neg = 0;
  int second_neg = 0;
  int third_neg = 0;

  int first_abs_neg = 0;
  int second_abs_neg = 0;

  for (auto number: numbers) {
    if (!seen_zero && number == 0) {
      seen_zero = true;
    }

    if (number > 0) {
      if (!seen_pos) seen_pos = true;
      handlePositiveNumber(number, first_pos, second_pos, third_pos);
    } else if (number < 0) {
      if (!seen_neg) seen_neg = true;
      handleNegativeNumber(number, first_neg, second_neg, third_neg, first_abs_neg, second_abs_neg);
    }
  }

  if (!seen_pos && seen_zero) {
    return 0;
  } else if (!seen_pos && !seen_zero) {
    return first_neg * second_neg * third_neg;
  } else if (!seen_neg) {
    return first_pos * second_pos * third_pos;
  }

  int all_positives = first_pos * second_pos * third_pos;
  int two_negatives = first_abs_neg * second_abs_neg * first_pos;
  return all_positives > two_negatives ? all_positives : two_negatives;
}

void handlePositiveNumber(int& number, int& first_pos, int& second_pos, int& third_pos) {
  if (number >= first_pos) {
    third_pos = second_pos;
    second_pos = first_pos;
    first_pos = number;

  } else if (number >= second_pos) {
    third_pos = second_pos;
    second_pos = number;

  } else if (number >= third_pos) {
    third_pos = number;
  }
}

void handleNegativeNumber(
  int& number,
  int& first_neg,
  int& second_neg,
  int& third_neg,
  int& first_abs_neg,
  int& second_abs_neg
) {
  if (first_neg == 0 || number >= first_neg) {
    third_neg = second_neg;
    second_neg = first_neg;
    first_neg = number;

  } else if (second_neg == 0 || number >= second_neg) {
    third_neg = second_neg;
    second_neg = number;

  } else if (third_neg == 0 || number >= third_neg) {
    third_neg = number;
  }

  if (number <= first_abs_neg) {
    second_abs_neg = first_abs_neg;
    first_abs_neg = number;
  } else if (number <= second_abs_neg) {
    second_abs_neg = number;
  }
}

int main() {
  vector<int> input{};
  ASSERT_EQUALS(maximumProduct(input), 0);

  vector<int> input1{1,2,3};
  ASSERT_EQUALS(maximumProduct(input1), 6);

  vector<int> input2{-1,-2,-3};
  ASSERT_EQUALS(maximumProduct(input2), -6);

  vector<int> input3{1,2,3,4};
  ASSERT_EQUALS(maximumProduct(input3), 24);

  vector<int> input4{-1,-2,-3,-4};
  ASSERT_EQUALS(maximumProduct(input4), -6);

  vector<int> input5{-1,-2,-3,0};
  ASSERT_EQUALS(maximumProduct(input5), 0);

  vector<int> input6{1,-1,0,-2,-3,4};
  ASSERT_EQUALS(maximumProduct(input6), 24);

  vector<int> input7{3,-1,3,-2,-3,4};
  ASSERT_EQUALS(maximumProduct(input7), 36);
}
