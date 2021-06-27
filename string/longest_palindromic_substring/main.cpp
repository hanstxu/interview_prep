#include "../../test.h"
using namespace std;

/**
 * Given a string, return the longest palindromic
 * substring in that string.
 */
string longestPalindrome(string s) {
  int palindrome_start = 0;
  int palindrome_end = 0;

  for (int i = 0; i < s.size(); i++) {
    int start = i;
    int end = i;

    while (start >= 0 && end < s.size()) {
      if (s[start] == s[end]) {
        int length = end - start + 1;
        int palindrome_length = palindrome_end - palindrome_start + 1;
        if (length > palindrome_length) {
          palindrome_start = start;
          palindrome_end = end;
        }

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
        int length = end - start + 1;
        int palindrome_length = palindrome_end - palindrome_start + 1;
        if (length > palindrome_length) {
          palindrome_start = start;
          palindrome_end = end;
        }

        start--;
        end++;

      } else {
        break;
      }
    }
  }

  return s.substr(palindrome_start, palindrome_end - palindrome_start + 1);
}

int main() {
  ASSERT_EQUALS(longestPalindrome(""), "");
  ASSERT_EQUALS(longestPalindrome("abcd"), "a");
  ASSERT_EQUALS(longestPalindrome("dabacd"), "aba");
  ASSERT_EQUALS(longestPalindrome("dabacddc"), "cddc");
  ASSERT_EQUALS(longestPalindrome("dcabacddc"), "dcabacd");

  ASSERT_EQUALS(longestPalindrome("babad"), "bab");
  ASSERT_EQUALS(longestPalindrome("cbbd"), "bb");
  ASSERT_EQUALS(longestPalindrome("a"), "a");
  ASSERT_EQUALS(longestPalindrome("ac"), "a");
}