#include "../../test.h"
#include "../trie.h"

using namespace std;

/**
 * Design a data structure that supports adding new words and
 * determining if words have been added to the data structure.
 *
 * The '.' character is a wildcard character and can match with
 * any word.
 */
class WordDictionary {
public:
  virtual void addWord(string word) = 0;
  virtual bool search(string word) = 0;
};

class WordDictionaryTrie: public WordDictionary {
private:
  TrieNode* root;

  bool search(string& word, TrieNode* node_start, int start) {
    TrieNode* curr = node_start;

    for (int i = start; i < word.size(); ++i) {
      if (word[i] == '.') {
        for (auto& m: curr->getChildren()) {
          if (search(word, m.second, i + 1)) {
            return true;
          }
        }

        return false;
      }

      if (!curr->containsKey(word[i])) {
        return false;
      }

      curr = curr->getNextNode(word[i]);
    }

     return curr->isEnd();
  }

public:
  WordDictionaryTrie() {
    this->root = new TrieNode();
  }

  void addWord(string word) {
    TrieNode* curr = root;

    for (char c: word) {
      if (!curr->containsKey(c)) {
        curr->addKey(c);
      }

      curr = curr->getNextNode(c);
    }

    curr->setEnd(true);
  }

  bool search(string word) {
    return search(word, root, 0);
  }
};

class WordDictionaryHashTable: public WordDictionary {
private:
  unordered_map<int, vector<string>> size_to_words;

  bool isEqual(string word, string pattern) {
    for (int i = 0; i < word.size(); ++i) {
      if (pattern[i] == '.') {
        continue;
      }

      if (word[i] != pattern[i]) {
        return false;
      }
    }

    return true;
  }

public:
  WordDictionaryHashTable() {
    this->size_to_words = unordered_map<int, vector<string>>();
  }

  void addWord(string word) {
    size_to_words[word.size()].push_back(word);
  }

  bool search(string word) {
    for (string s: size_to_words[word.size()]) {
      if (isEqual(s, word)) {
        return true;
      }
    }

    return false;
  }
};

int main() {
  WordDictionary* dictionary;
  WordDictionaryTrie trie_dictionary = WordDictionaryTrie();
  WordDictionaryHashTable hash_table_dictionary = WordDictionaryHashTable();

  dictionary = &hash_table_dictionary;

  dictionary->addWord("bad");
  dictionary->addWord("dad");
  dictionary->addWord("mad");

  ASSERT_FALSE(dictionary->search(""));
  ASSERT_FALSE(dictionary->search("pad"));
  ASSERT_TRUE(dictionary->search("bad"));
  ASSERT_TRUE(dictionary->search("dad"));
  ASSERT_TRUE(dictionary->search("mad"));

  ASSERT_FALSE(dictionary->search("."));
  ASSERT_TRUE(dictionary->search(".ad"));
  ASSERT_TRUE(dictionary->search("b.."));
}
