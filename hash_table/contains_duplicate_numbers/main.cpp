#include "../../test.h"
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& numbers) {
  unordered_set<int> seen;
  for (auto number: numbers) {
    if (seen.find(number) != seen.end()) {
      return true;
    }

    seen.insert(number);
  }

  return false;
}

int main() {
  vector<int> numbers1{};
  ASSERT_FALSE(containsDuplicate(numbers1));

  vector<int> numbers2{1};
  ASSERT_FALSE(containsDuplicate(numbers2));

  vector<int> numbers3{1,2};
  ASSERT_FALSE(containsDuplicate(numbers3));

  vector<int> numbers4{1,1};
  ASSERT_TRUE(containsDuplicate(numbers4));

  vector<int> numbers5{1,2,3};
  ASSERT_FALSE(containsDuplicate(numbers5));

  vector<int> numbers6{1,2,1};
  ASSERT_TRUE(containsDuplicate(numbers6));
}
