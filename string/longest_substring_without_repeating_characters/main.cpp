#include "../../test.h"
#include <unordered_set>
using namespace std;

/**
 * Given a string, find the length of the longest
 * substring without repeating characters.
 */
int lengthOfLongestSubString(string s) {
  int max_length = 0;

  unordered_set<char> seen;

  int i = 0;
  int start = 0;
  int end = 0;

  while (i < s.size()) {
    if (seen.find(s[i]) == seen.end()) {
      seen.insert(s[i]);
      end++;
      i++;

      max_length = max(max_length, end - start);

    } else {
      seen.erase(s[start]);
      start++;
    }

  }

  return max_length;
}

int main() {
  ASSERT_EQUALS(lengthOfLongestSubString(""), 0);
  ASSERT_EQUALS(lengthOfLongestSubString("hello"), 3);
  ASSERT_EQUALS(lengthOfLongestSubString("abcabcbb"), 3);
  ASSERT_EQUALS(lengthOfLongestSubString("bbbbb"), 1);
  ASSERT_EQUALS(lengthOfLongestSubString("pwwkew"), 3);
  ASSERT_EQUALS(lengthOfLongestSubString("au"), 2);
  ASSERT_EQUALS(lengthOfLongestSubString("abcdefghijklmnopqrstuvwxyz"), 26);
  ASSERT_EQUALS(lengthOfLongestSubString("abcdeafghij"), 10);
}
