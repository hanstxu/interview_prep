#include "../../test.h"
using namespace std;

/**
 * Given a string, count the number of palindromic
 * substrings.
 */
int countSubstrings(string s) {
  int count = 0;
  for (int i = 0; i < s.size(); i++) {
    int start = i;
    int end = i;

    while (start >= 0 && end < s.size()) {
      if (s[start] == s[end]) {
        count++;
        start--;
        end++;

      } else {
        break;
      }
    }
  }

  for (int i = 1; i < s.size(); i++) {
    int start = i - 1;
    int end = i;

    while (start >= 0 && end < s.size()) {
      if (s[start] == s[end]) {
        count++;
        start--;
        end++;

      } else {
        break;
      }
    }
  }

  return count;
}

int main() {
  ASSERT_EQUALS(countSubstrings(""), 0);
  ASSERT_EQUALS(countSubstrings("abc"), 3);
  ASSERT_EQUALS(countSubstrings("aaa"), 6);

  ASSERT_EQUALS(countSubstrings("aabc"), 5);
  ASSERT_EQUALS(countSubstrings("aabaccabaa"), 19);
}
