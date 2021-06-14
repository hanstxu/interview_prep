#include "../../test.h"
#include "../trie.h"
using namespace std;

/**
 * A trie, also known as a prefix tree, is a type of search key
 * used for locating specific keys in a set.
 *
 * Implement a trie data structure.
 */
class Trie {
public:
  Trie() {
    this->root = new TrieNode();
  }

  void insert(string word) {
    TrieNode* curr = root;

    for (char c: word) {
      if (curr->containsKey(c)) {
        curr = curr->getNextNode(c);

      } else {
        curr = curr->addKey(c);
      }
    }

    curr->setEnd(true);
  }

  bool search(string word) {
    TrieNode* curr = root;
    for (char c: word) {
      if (!curr->containsKey(c)) {
        return false;
      }

      curr = curr->getNextNode(c);
    }

    return curr->isEnd();
  }

  bool startsWith(string prefix) {
    TrieNode* curr = root;
    for (char c: prefix) {
      if (!curr->containsKey(c)) {
        return false;
      }

      curr = curr->getNextNode(c);
    }

    return true;
  }

private:
  TrieNode* root;
};

int main() {
  Trie trie = Trie();

  ASSERT_FALSE(trie.search(""));
  ASSERT_TRUE(trie.startsWith(""));

  trie.insert("");
  ASSERT_TRUE(trie.search(""));


  ASSERT_FALSE(trie.startsWith("test"));

  trie.insert("test");
  ASSERT_FALSE(trie.search("t"));
  ASSERT_FALSE(trie.search("te"));
  ASSERT_FALSE(trie.search("tes"));
  ASSERT_TRUE(trie.search("test"));
  ASSERT_FALSE(trie.search("test0"));
  ASSERT_TRUE(trie.startsWith("t"));
  ASSERT_TRUE(trie.startsWith("te"));
  ASSERT_TRUE(trie.startsWith("tes"));
  ASSERT_TRUE(trie.startsWith("test"));
  ASSERT_FALSE(trie.startsWith("test0"));


  trie.insert("apple");
  ASSERT_TRUE(trie.search("apple"));
  ASSERT_FALSE(trie.search("app"));
  ASSERT_TRUE(trie.startsWith("app"));

  trie.insert("app");
  ASSERT_TRUE(trie.search("app"));
  ASSERT_TRUE(trie.startsWith("app"));
}