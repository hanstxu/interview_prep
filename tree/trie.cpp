#include "trie.h"
#include <unordered_map>

TrieNode::TrieNode() {
  this->is_end = false;
  this->word = "";
  this->children = std::unordered_map<char, TrieNode*>();
}

bool TrieNode::containsKey(char c) {
  return children.find(c) != children.end();
}

TrieNode* TrieNode::addKey(char c) {
  if (children.find(c) != children.end()) {
    return children[c];
  }

  TrieNode* new_node = new TrieNode();
  children[c] = new_node;
  return new_node;
}

TrieNode* TrieNode::getNextNode(char c) {
  if (children.find(c) == children.end()) {
    return nullptr;
  }

  return children[c];
}

bool TrieNode::isEnd() {
  return is_end;
}

void TrieNode::setEnd(bool is_end) {
  this->is_end = is_end;
}

std::string TrieNode::getWord() {
  return word;
}

void TrieNode::setWord(std::string word) {
  this->word = word;
}

std::unordered_map<char, TrieNode*> TrieNode::getChildren() {
  return children;
}
