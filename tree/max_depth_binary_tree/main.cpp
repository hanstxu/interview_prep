#include "../../test.h"
#include "../tree.h"
#include <algorithm>
using namespace std;

/**
 * Given the root of a binary tree, return the maximum depth.
 */
int maxDepth(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }

  int left_depth = 1 + maxDepth(root->left);
  int right_depth = 1 + maxDepth(root->right);
  return max(left_depth, right_depth);
}

int main() {
  TreeNode* empty_tree = nullptr;
  ASSERT_EQUALS(maxDepth(empty_tree), 0);

  TreeNode* single_node = new TreeNode(5);
  ASSERT_EQUALS(maxDepth(single_node), 1);

  TreeNode* right_node1 = new TreeNode(2);
  TreeNode* input1 = new TreeNode(1, nullptr, right_node1);
  ASSERT_EQUALS(maxDepth(input1), 2);

  TreeNode* right_node2 = new TreeNode(20, new TreeNode(15), new TreeNode(7));
  TreeNode* input2 = new TreeNode(3, new TreeNode(9), right_node2);
  ASSERT_EQUALS(maxDepth(input2), 3);
}