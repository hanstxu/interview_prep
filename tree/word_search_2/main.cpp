#include "../../test.h"
#include "../trie.h"

#include <vector>
using namespace std;

/**
 * Given a board of characters and a list of words, return
 * all the words on the board.
 */
class Trie {
public:
  Trie() {
    this->root = new TrieNode();
  }

  Trie(vector<string> words) {
    this->root = new TrieNode();

    for (string word: words) {
      addWord(word);
    }
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
    curr->setWord(word);
  }

  TrieNode* getRoot() {
    return root;
  }

private:
  TrieNode* root;
};

void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
  char c = board[i][j];
  if (c == '#' || !node->containsKey(c)) {
    return;
  }

  node = node->getNextNode(c);
  if (node->isEnd()) {
    result.push_back(node->getWord());
    node->setEnd(false); // remove duplicates
  }

  board[i][j] = '#';

  if (i > 0) {
    dfs(board, i - 1, j, node, result);
  }

  if (j > 0) {
    dfs(board, i, j - 1, node, result);
  }

  if (i < board.size() - 1) {
    dfs(board, i + 1, j, node, result);
  }

  if (j < board[0].size() - 1) {
    dfs(board, i, j + 1, node, result);
  }

  board[i][j] = c;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
  Trie trie = Trie(words);
  TrieNode* root = trie.getRoot();

  vector<string> result;
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[0].size(); ++j) {
      dfs(board, i, j, root, result);
    }
  }

  return result;
}

int main() {
  vector<vector<char>> board_1 = {{'a','b'},
                                  {'c','d'}};
  vector<string> board_1_words = {"abcb", "abdc", "acd", "cd", "abcd"};
  vector<string> board_1_expected_result = {"acd", "abdc", "cd"};
  ASSERT_EQUALS(findWords(board_1, board_1_words), board_1_expected_result);

  vector<vector<char>> board_2 = {{'o','a','a','n'},
                                  {'e','t','a','e'},
                                  {'i','h','k','r'},
                                  {'i','f','l','v'}};
  vector<string> board_2_words = {"oath", "pea", "eat", "rain"};
  vector<string> board_2_expected_result = {"oath", "eat"};
  ASSERT_EQUALS(findWords(board_2, board_2_words), board_2_expected_result);
}
