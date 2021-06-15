#include "../../test.h"

#include <unordered_map>
using namespace std;

/**
 * You are given a string filled with uppercase letters.
 *
 * You are allowed an operation to change any character
 * in the string to any uppercase letter.
 *
 * Return the longest substring containing the same letter
 * given that you are allowed to perform the operation
 * described above k times.
 */
typedef unordered_map<char, int> Hash_Table;

int characterReplacement(string s, int k) {
  Hash_Table counts;

  int max_length = 0;
  int max_count = 0;

  int start = 0;
  int end = 0;

  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    counts[c]++;

    if (counts[c] > max_count) {
      max_count = counts[c];
      end++;
      max_length = end - start;

    } else if (max_length - max_count < k) {
      end++;
      max_length = end - start;

    } else {
      counts[s[start]]--;

      start++;
      end++;
    }
  }

  return max_length;
}

int main() {
  ASSERT_EQUALS(characterReplacement("", 2), 0);
  ASSERT_EQUALS(characterReplacement("ABAB", 2), 4);
  ASSERT_EQUALS(characterReplacement("AABABBA", 1), 4);
  ASSERT_EQUALS(characterReplacement("ABABC", 2), 4);
  ASSERT_EQUALS(characterReplacement("ABABCBB", 2), 6);
}
