#include "../../test.h"
#include "../tree.h"

/**
 * Given the root of a binary tree, invert the tree
 * and return the root of that inverted tree;
 */
TreeNode* invertTree(TreeNode* root) {
  if (root == nullptr) {
    return root;
  }

  TreeNode* left = invertTree(root->right);
  TreeNode* right = invertTree(root->left);
  root->left = left;
  root->right = right;
  return root;
}

int main() {
  TreeNode* empty_tree = nullptr;
  ASSERT_EQUALS(invertTree(empty_tree), empty_tree);

  TreeNode* input1 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
  TreeNode* output1 = new TreeNode(2, new TreeNode(3), new TreeNode(1));
  ASSERT_EQUALS(invertTree(input1), output1);

  TreeNode* input2 = new TreeNode(
    4,
    new TreeNode(2, new TreeNode(1), new TreeNode(3)),
    new TreeNode(7, new TreeNode(6), new TreeNode(9)));

  TreeNode* output2 = new TreeNode(
    4,
    new TreeNode(7, new TreeNode(9), new TreeNode(6)),
    new TreeNode(2, new TreeNode(3), new TreeNode(1)));
  ASSERT_EQUALS(invertTree(input2), output2);
}
