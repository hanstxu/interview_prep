#include "../../test.h"
#include <vector>
using namespace std;

/**
 * Given a board of characters, return whether the word
 * exists in the board by combining letters horizontally
 * and vertically without using cells more than once.
 */
bool dfs(vector<vector<char>>& board, int i, int j, string& word, int word_index);

bool exist(vector<vector<char>>& board, string word) {
  if (word.empty()) {
    return true;
  }

  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[0].size(); ++j) {
      if (board[i][j] == word[0] && dfs(board, i, j, word, 0)) {
        return true;
      }
    }
  }

  return false;
}

bool dfs(vector<vector<char>>& board, int i, int j, string& word, int word_index) {
  if (board[i][j] != word[word_index]) {
    return false;
  }

  if (word_index == word.size() - 1) {
    return true;
  }

  bool was_found = false;
  char c = word[word_index];
  board[i][j] = '*';

  if (i > 0) {
    was_found = dfs(board, i - 1, j, word, word_index + 1);
  }

  if (!was_found && i < board.size() - 1) {
    was_found = dfs(board, i + 1, j, word, word_index + 1);
  }

  if (!was_found && j > 0) {
    was_found = dfs(board, i, j - 1, word, word_index + 1);
  }

  if (!was_found && j < board[0].size() - 1) {
    was_found = dfs (board, i, j + 1, word, word_index + 1);
  }

  board[i][j] = c;

  return was_found;
}

int main() {
  vector<vector<char>> no_board;

  vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                {'S', 'F', 'C', 'S'},
                                {'A', 'D', 'E', 'E'}};

  vector<vector<char>> small_board = {{'a'}};

  ASSERT_FALSE(exist(no_board, "ABCCED"));
  ASSERT_TRUE(exist(board, ""));
  ASSERT_TRUE(exist(board, "ABCCED"));
  ASSERT_TRUE(exist(board, "SEE"));
  ASSERT_FALSE(exist(board, "ABCB"));
  ASSERT_TRUE(exist(small_board, "a"));
}
