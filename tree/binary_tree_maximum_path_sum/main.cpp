#include "../../test.h"
#include "../tree.h"
#include <climits>
using namespace std;

/**
 * Given a binary tree, return the maximum path sum of any path
 * in the binary tree.
 *
 * Note that the path in this problem is a sequence of distinct nodes
 * joined by edges.
 */
int maxPathDown(TreeNode* node, int& max_value);

int maxPathSum(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }

  int max_value = INT_MIN;
  maxPathDown(root, max_value);
  return max_value;
}

int maxPathDown(TreeNode* node, int& max_value) {
  if (node == nullptr) {
    return 0;
  }

  int left = max(maxPathDown(node->left, max_value), 0);
  int right = max(maxPathDown(node->right, max_value), 0);
  max_value = max(max_value, node->value + left + right);

  return node->value + max(left, right);
}

int main() {
  TreeNode* empty_tree = nullptr;
  ASSERT_EQUALS(maxPathSum(empty_tree), 0);

  TreeNode* input_1 = new TreeNode(5, new TreeNode(2), new TreeNode(7));
  ASSERT_EQUALS(maxPathSum(input_1), 14);

  TreeNode* input_2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  ASSERT_EQUALS(maxPathSum(input_2), 6);

  TreeNode* input_3 = new TreeNode(
    -10,
    new TreeNode(9),
    new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  ASSERT_EQUALS(maxPathSum(input_3), 42);
}
