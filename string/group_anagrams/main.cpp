#include "../../test.h"
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Given an array of strings, group the anagrams together, in any order.
 * in any order.
 *
 * An anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, using all the original letters exactly once.
 */
string countingSort(string word) {
  int counter[26] = {0};
  for (char c: word) {
    counter[c - 'a']++;
  }

  string sorted_word;
  for (int i = 0; i < 26; ++i) {
    sorted_word += string(counter[i], 'a' + i);
  }

  return sorted_word;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<string, vector<string>> anagrams;
  for (string str: strs) {
    string key = countingSort(str);
    anagrams[key].push_back(str);
  }

  vector<vector<string>> result;
  for (auto& it: anagrams) {
    result.push_back(it.second);
  }

  return result;
}

int main() {
  vector<string> no_strings;
  vector<vector<string>> empty_group_of_strings;
  ASSERT_EQUALS(groupAnagrams(no_strings), empty_group_of_strings);

  vector<string> one_string = {"a"};
  ASSERT_EQUALS(groupAnagrams(one_string), vector<vector<string>>{{"a"}});

  vector<string> input_1 = {"ab", "ba", "cc", "de", "ed"};
  ASSERT_EQUALS(groupAnagrams(input_1), (vector<vector<string>>{{"de", "ed"},
                                                                {"ab", "ba"},
                                                                {"cc"}}));

  vector<string> input_2 = {"eat", "tea", "tan", "ate", "nat", "bat"};
  ASSERT_EQUALS(groupAnagrams(input_2), (vector<vector<string>>{{"eat", "tea", "ate"},
                                                                {"bat"},
                                                                {"tan", "nat"}}));
}
