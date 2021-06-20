#include "../../test.h"
#include <stack>
using namespace std;

/**
 * Given a string that just contains parenthesis characters (i.e.
 * '(', ')', '[', ']', '{', '}'), determine if the string correctly
 * closes each open parenthesis.
 */
bool isValid(string s) {
  stack<char> parenthesis;
  for (auto c: s) {
    switch (c) {
      case '(':
      case '[':
      case '{':
        parenthesis.push(c);
        continue;
        break;

      default:
        if (parenthesis.empty()) {
          return false;
        }
        break;
    }

    if (c == ')' && parenthesis.top() != '(') {
      return false;

    } else if (c == ']' && parenthesis.top() != '[') {
      return false;

    } else if (c == '}' && parenthesis.top() != '{') {
      return false;
    }

    parenthesis.pop();
  }


  return parenthesis.empty();
}

int main() {
  ASSERT_TRUE(isValid(""));

  ASSERT_FALSE(isValid("("));
  ASSERT_FALSE(isValid("["));
  ASSERT_FALSE(isValid("{"));

  ASSERT_FALSE(isValid(")"));
  ASSERT_FALSE(isValid("]"));
  ASSERT_FALSE(isValid("}"));

  ASSERT_TRUE(isValid("()[]{}"));
  ASSERT_FALSE(isValid("(]"));
  ASSERT_FALSE(isValid("([)]"));
  ASSERT_TRUE(isValid("{[]}"));
}
