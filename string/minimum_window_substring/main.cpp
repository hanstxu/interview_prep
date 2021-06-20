#include "../../test.h"

#include <unordered_map>
using namespace std;

/**
 * Given two strings, s and t, return the minimum substring of s
 * that includes every character in t (i.e. including duplicates).
 *
 * Return an empty string if there is no such string.
 */
typedef unordered_map<char, int> Character_Counts;

string minWindow(string s, string t) {
  if (s.empty() || t.empty()) {
    return "";
  }

  Character_Counts t_counts;
  int total_count = 0;
  for (auto c: t) {
    t_counts[c]++;
    total_count++;
  }

  Character_Counts window_counts;
  int match_count = 0;

  string result;
  int min_length = s.size() + 1;

  int start = 0;
  int end = 0;
  
  while (match_count == total_count || end < s.size()) {
    if (match_count < total_count) {
      char c = s[end];
      if (window_counts[c] < t_counts[c]) {
        match_count++;
      }

      window_counts[c]++;

      if (match_count == total_count && (end - start + 1) < min_length) {
        min_length = end - start + 1;
        result = s.substr(start, end + 1);
      }

      end++;

    } else {
      char c = s[start];
      if (window_counts[c] <= t_counts[c]) {
        match_count--;
      }

      window_counts[c]--;
      start++;

      if (match_count == total_count && (end - start) < min_length) {
        min_length = end - start;
        result = s.substr(start, end - start);
      }
    }
  }

  return result;
}

int main() {
  ASSERT_EQUALS(minWindow("A", ""), "");
  ASSERT_EQUALS(minWindow("", "A"), "");
  ASSERT_EQUALS(minWindow("BBBAAAAC", "A"), "A");

  ASSERT_EQUALS(minWindow("ABBBBZ", "ZA"), "ABBBBZ");
  ASSERT_EQUALS(minWindow("BABBBZ", "ZA"), "ABBBZ");
  ASSERT_EQUALS(minWindow("BBBBAZ", "ZA"), "AZ");
  ASSERT_EQUALS(minWindow("BBBBAZA", "ZA"), "AZ");

  ASSERT_EQUALS(minWindow("ADOBECODEBANC", "ABC"), "BANC");
  ASSERT_EQUALS(minWindow("TABHISCZLKYRSTAC", "STY"), "YRST");
  
}
