#include "../../test.h"
#include "../tree.h"
#include <vector>
#include <queue>
using namespace std;

/**
 * Given a binary tree, return an array of values obtained from
 * a level order traversal.
 */
vector<vector<int>> levelOrder(TreeNode* root) {
  if (root == nullptr) {
    return vector<vector<int>>();
  }

  vector<vector<int>> result;

  queue<TreeNode*> nodes;
  nodes.push(root);
  nodes.push(nullptr);

  vector<int> level;

  while (!nodes.empty()) {
    TreeNode* curr = nodes.front();
    nodes.pop();

    if (curr == nullptr) {
      result.push_back(level);
      level.clear();

      if (!nodes.empty()) {
        nodes.push(nullptr);
      }

    } else {
      level.push_back(curr->value);
      if (curr->left != nullptr) {
        nodes.push(curr->left);
      }

      if (curr->right != nullptr) {
        nodes.push(curr->right);
      }
    }
  }

  return result;
}

int main() {
  TreeNode* empty_tree = nullptr;
  ASSERT_TRUE(levelOrder(empty_tree).empty());

  TreeNode* input_1 = new TreeNode(1);
  ASSERT_EQUALS(levelOrder(input_1), vector<vector<int>>{{1}});

  TreeNode* input_2 = new TreeNode(
    3,
    new TreeNode(9),
    new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  ASSERT_EQUALS(levelOrder(input_2), (vector<vector<int>>{{3},{9,20},{15,7}}));
}
