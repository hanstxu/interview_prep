#include "../../test.h"
using namespace std;

/**
 * Given a string, determine if it is a palindrome if we
 * only consider alphanumeric characters and ignore cases.
 */
bool isPalindrome(string s) {
  int start = 0;
  int end = s.size() - 1;
  while (start < end) {
    if (!isalnum(s[start])) {
      start++;
      continue;
    }

    if (!isalnum(s[end])) {
      end--;
      continue;
    }

    if (tolower(s[start]) != tolower(s[end])) {
      return false;
    }

    start++;
    end--;
  }

  return true;
}

int main() {
  ASSERT_TRUE(isPalindrome(""));
  ASSERT_TRUE(isPalindrome("a"));
  ASSERT_TRUE(isPalindrome("Aa"));
  ASSERT_TRUE(isPalindrome("A1a"));
  ASSERT_TRUE(isPalindrome("aB2bA"));

  ASSERT_FALSE(isPalindrome("aB23bA"));
  ASSERT_FALSE(isPalindrome("aB22bz"));

  ASSERT_TRUE(isPalindrome("A man, a plan, a canal: Panama"));
  ASSERT_FALSE(isPalindrome("race a car"));
}
