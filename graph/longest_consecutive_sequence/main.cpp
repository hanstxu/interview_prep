#include "../../test.h"
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * Given an unsorted array of integers, return the length of
 * the longest consecutive elements sequence.
 */
int longestConsecutive(vector<int>& numbers) {
  unordered_set<int> elements;
  for (int number: numbers) {
    elements.insert(number);
  }

  int max_consecutive_count = 0;

  for (auto element: elements) {
    if (elements.find(element - 1) == elements.end()) {

      int consecutive_count = 1;
      while (elements.find(++element) != elements.end()) {
        consecutive_count++;
      }

      max_consecutive_count = max(max_consecutive_count, consecutive_count);
    }
  }

  return max_consecutive_count;
}

int main() {
  vector<int> no_elements;
  ASSERT_EQUALS(longestConsecutive(no_elements), 0);

  vector<int> elements_1 = {1,3,7,6,4,10,8};
  ASSERT_EQUALS(longestConsecutive(elements_1), 3);

  vector<int> elements_2 = {100,4,200,1,3,2};
  ASSERT_EQUALS(longestConsecutive(elements_2), 4);

  vector<int> elements_3 = {0,3,7,2,5,8,4,6,0,1};
  ASSERT_EQUALS(longestConsecutive(elements_3), 9);
}