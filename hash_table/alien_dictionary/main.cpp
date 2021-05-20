#include "../../test.h"
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * Given a list of strings and an order of letters, return true
 * if the words are sorted lexicographically according to that
 * order
 */
class AlienDictionary {
  public:
    AlienDictionary(string order) {
      for (int i = 0; i < order.length(); i++) {
        char c = order[i];
        ordinal_map[c] = i;
      }
    }

    bool isSorted(vector<string>& words) {
      int n = words.size();
      for (int i = 0; i < n - 1; i++) {
        if (!inOrder(words[i], words[i + 1])) {
          return false;
        }
      }
      return true;
    }

  private:
    unordered_map<char, int> ordinal_map;

    bool inOrder(string word1, string word2) {
      int min_length = min(word1.length(), word2.length());
      for (int i = 0; i < min_length; i++) {
        char c1 = word1[i];
        char c2 = word2[i];
        
        if (ordinal_map[c1] > ordinal_map[c2]) {
          return false;
        } else if (ordinal_map[c1] < ordinal_map[c2]) {
          return true;
        }
      }
      
      return word1.length() == min_length;
    }
};

int main() {
  AlienDictionary dict("bac");

  vector<string> test_case1;
  ASSERT_TRUE(dict.isSorted(test_case1));

  vector<string> test_case2{"aa", "aa"};
  ASSERT_TRUE(dict.isSorted(test_case2));

  vector<string> test_case3{"a", "b", "c"};
  ASSERT_FALSE(dict.isSorted(test_case3));

  vector<string> test_case4{"b", "a", "c"};
  ASSERT_TRUE(dict.isSorted(test_case4));

  vector<string> test_case5{"a","aa"};
  ASSERT_TRUE(dict.isSorted(test_case5));

  vector<string> test_case6{"aa","a"};
  ASSERT_FALSE(dict.isSorted(test_case6));
}