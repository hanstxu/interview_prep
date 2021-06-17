#include "../../test.h"

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

/**
 * Given an array of equal length strings, determine
 * if the array can be rearranged in a way such that
 * consecutive pair of strings differ by exactly one
 * character.
 */
bool differByOne(string a, string b) {
  if (a.size() != b.size()) {
    return false;
  }

  int difference = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) {
      difference++;
    }
  }

  return difference == 1;
}

bool stringsRearrangement(vector<string>& inputArray) {
  if (inputArray.empty()) {
    return true;
  }

  unordered_map<string, vector<string>> adjacency_list;

  for (string word: inputArray) {
    for (string compare_word: inputArray) {
      if (word == compare_word) {
        continue;
      }

      if (differByOne(word, compare_word)) {
        adjacency_list[word].push_back(compare_word);
      }
    }
  }

  int count = 1;
  unordered_set<string> seen = { inputArray[0] };

  queue<string> nodes;
  nodes.push(inputArray[0]);

  while (!nodes.empty()) {
    string node = nodes.front();
    nodes.pop();

    vector<string> neighbors = adjacency_list[node];
    for (string neighbor: neighbors) {
      if (seen.find(neighbor) != seen.end()) {
        continue;
      }

      seen.insert(neighbor);
      nodes.push(neighbor);
      count++;
    }
  }

  return count == inputArray.size();
}

int main() {
  vector<string> empty_array;
  ASSERT_TRUE(stringsRearrangement(empty_array));

  vector<string> input_1 = {"a", "aa", "aaa"};
  ASSERT_FALSE(stringsRearrangement(input_1));

  vector<string> input_2 = {"a", "b", "c"};
  ASSERT_TRUE(stringsRearrangement(input_2));

  vector<string> input_3 = {"abb", "acb", "acc", "bbb", "bcb"};
  ASSERT_TRUE(stringsRearrangement(input_3));

  vector<string> input_4 = {"ab", "bb", "bc", "cc", "dd", "de", "fe", "ff"};
  ASSERT_FALSE(stringsRearrangement(input_4));
}
