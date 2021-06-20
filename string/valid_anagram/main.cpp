#include "../../test.h"
#include <unordered_map>
using namespace std;

/**
 * Given two word, determine if they are anagrams.
 *
 * A word is an anagram of another if they can be rearranged
 * to that other word.
 */
bool isAnagram(string s, string t) {
  if (s.size() != t.size()) {
    return false;
  }

  unordered_map<char, int> character_count;

  for (char c: s) {
    character_count[c]++;
  }

  for (char c: t) {
    if (character_count[c] <= 0) {
      return false;
    }

    character_count[c]--;
  }

  return true;
}

int main() {
  ASSERT_TRUE(isAnagram("", ""));
  ASSERT_FALSE(isAnagram("a", ""));
  ASSERT_FALSE(isAnagram("", "a"));

  ASSERT_TRUE(isAnagram("aba", "baa"));
  ASSERT_FALSE(isAnagram("aba", "bba"));
  ASSERT_FALSE(isAnagram("aba", "abc"));
  ASSERT_TRUE(isAnagram("ddabab", "abbadd"));
}
