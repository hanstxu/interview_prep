#include "../../test.h"
#include "../tree.h"
using namespace std;

/**
 * Given a binary search tree, return the kth smallest
 * element in the tree.
 *
 * The bound of values is from 0 to 10^4, inclusive.
 */
int kthSmallest(TreeNode* root, int k, int& count) {
  if (root == nullptr) {
    return -1;
  }

  int left_element = kthSmallest(root->left, k, count);
  if (left_element != -1) {
    return left_element;
  }

  count++;
  if (count == k) {
    return root->value;
  }

  return kthSmallest(root->right, k, count);
}

int kthSmallest(TreeNode* root, int k) {
  int count = 0;
  return kthSmallest(root, k, count);
}

int main() {
  TreeNode* empty_tree = nullptr;
  ASSERT_EQUALS(kthSmallest(empty_tree, 1), -1);

  TreeNode* tree_1 = new TreeNode(1);
  ASSERT_EQUALS(kthSmallest(tree_1, 1), 1);

  TreeNode* tree_2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
  ASSERT_EQUALS(kthSmallest(tree_2, 3), 3);

  TreeNode* tree_3 = new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(4));
  ASSERT_EQUALS(kthSmallest(tree_3, 1), 1);
  ASSERT_EQUALS(kthSmallest(tree_3, 2), 2);

  TreeNode* tree_4 = new TreeNode(
    5,
    new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)),
    new TreeNode(6));
  ASSERT_EQUALS(kthSmallest(tree_4, 3), 3);
}
