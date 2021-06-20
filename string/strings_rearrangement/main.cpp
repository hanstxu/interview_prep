#include "../../test.h"

#include <vector>
#include <algorithm>

#include <unordered_map>
#include <queue>
using namespace std;

/**
 * Given an array of equal length strings, determine
 * if the array can be rearranged in a way such that
 * consecutive pair of strings differ by exactly one
 * character.
 *
 * This is the Hamiltonian path problem.
 */
bool containsWordsOfSameLength(vector<string>& inputArray) {
  for (int i = 0; i < inputArray.size() - 1; ++i) {
    if (inputArray[i].size() != inputArray[i + 1].size()) {
      return false;
    }
  }

  return true;
}

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

bool isAnRearrangement(vector<string>& inputArray) {
  for (int i = 0; i < inputArray.size() - 1; ++i) {
    if (!differByOne(inputArray[i], inputArray[i + 1])) {
      return false;
    }
  }

  return true;
}

bool stringsRearrangement(vector<string>& inputArray) {
  if (inputArray.empty()) {
    return true;
  }

  if (!containsWordsOfSameLength(inputArray)) {
    return false;
  }

  sort(inputArray.begin(), inputArray.end());

  do {
    if (isAnRearrangement(inputArray)) {
      return true;
    }

  } while ( next_permutation(inputArray.begin(), inputArray.end()) );

  return false;
}

// Fails last test case
bool stringsRearrangementBfs(vector<string>& inputArray) {
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

  unordered_map<string, int> word_count;
  for (string word: inputArray) {
    word_count[word]++;
  }

  int count = 1;
  unordered_map<string, int> seen_words;
  seen_words[inputArray[0]] = 1;

  queue<string> nodes;
  nodes.push(inputArray[0]);

  while (!nodes.empty()) {
    string node = nodes.front();
    nodes.pop();

    vector<string> neighbors = adjacency_list[node];
    for (string neighbor: neighbors) {
      if (seen_words[neighbor] >= word_count[neighbor]) {
        continue;
      }

      seen_words[neighbor]++;
      nodes.push(neighbor);
      count++;
    }
  }

  return count == inputArray.size();
}

int main() {
  vector<string> empty_array;
  ASSERT_TRUE(stringsRearrangement(empty_array));
  ASSERT_TRUE(stringsRearrangementBfs(empty_array));

  vector<string> input_1 = {"a", "aa", "aaa"};
  ASSERT_FALSE(stringsRearrangement(input_1));
  ASSERT_FALSE(stringsRearrangementBfs(input_1));

  vector<string> input_2 = {"a", "b", "c"};
  ASSERT_TRUE(stringsRearrangement(input_2));
  ASSERT_TRUE(stringsRearrangementBfs(input_2));

  vector<string> input_3 = {"abb", "acb", "acc", "bbb", "bcb"};
  ASSERT_TRUE(stringsRearrangement(input_3));
  ASSERT_TRUE(stringsRearrangementBfs(input_3));

  vector<string> input_4 = {"ab", "bb", "bc", "cc", "dd", "de", "fe", "ff"};
  ASSERT_FALSE(stringsRearrangement(input_4));
  ASSERT_FALSE(stringsRearrangementBfs(input_4));

  vector<string> input_5 = {"abc", "abx", "axx", "abx", "abc"};
  ASSERT_TRUE(stringsRearrangement(input_5));
  ASSERT_TRUE(stringsRearrangementBfs(input_5));

  vector<string> input_6 = {"abc", "aba", "abc"};
  ASSERT_TRUE(stringsRearrangement(input_6));
  ASSERT_TRUE(stringsRearrangementBfs(input_6));

  vector<string> input_7 = {"abc", "abx", "axx", "abc"};
  ASSERT_FALSE(stringsRearrangement(input_7));
  ASSERT_FALSE(stringsRearrangementBfs(input_7));
}
