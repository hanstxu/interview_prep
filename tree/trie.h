#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>

class TrieNode {
public:
  TrieNode();

  bool containsKey(char c);
  TrieNode* addKey(char c);
  TrieNode* getNextNode(char c);

  bool isEnd();
  void setEnd(bool is_end);

  std::string getWord();
  void setWord(std::string word);

  std::unordered_map<char, TrieNode*> getChildren();

private:
  bool is_end;
  std::string word;
  std::unordered_map<char, TrieNode*> children;
};

#endif
