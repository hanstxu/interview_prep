#include "../../test.h"
#include "../tree.h"

#include <algorithm>
using namespace std;

/**
 * Given a binary search tree, find the lowest common ancestor
 * of two given nodes in the BST.
 */
TreeNode* helper(TreeNode* root, int min_value, int max_value) {
  if (root->value >= min_value && root->value <= max_value) {
    return root;
  }

  if (root->value > max_value) {
    return helper(root->left, min_value, max_value);
  }

  return helper(root->right, min_value, max_value);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  return helper(root, min(p->value, q->value), max(p->value, q->value));
}

int main() {
  TreeNode* bst_left_1 = new TreeNode(1);
  TreeNode* bst_right_1 = new TreeNode(3);
  TreeNode* bst_1 = new TreeNode(2);

  ASSERT_EQUALS(lowestCommonAncestor(bst_1, bst_left_1, bst_right_1), bst_1);
  ASSERT_EQUALS(lowestCommonAncestor(bst_1, bst_right_1, bst_left_1), bst_1);
  ASSERT_EQUALS(lowestCommonAncestor(bst_1, bst_left_1, bst_1), bst_1);
  ASSERT_EQUALS(lowestCommonAncestor(bst_1, bst_1, bst_left_1), bst_1);
  ASSERT_EQUALS(lowestCommonAncestor(bst_1, bst_right_1, bst_1), bst_1);
  ASSERT_EQUALS(lowestCommonAncestor(bst_1, bst_1, bst_right_1), bst_1);

  TreeNode* bst_left_2b = new TreeNode(4, new TreeNode(3), new TreeNode(5));
  TreeNode* bst_left_2a = new TreeNode(2, new TreeNode(0), bst_left_2b);
  TreeNode* bst_right_2 = new TreeNode(8, new TreeNode(7), new TreeNode(9));
  TreeNode* bst_2 = new TreeNode(6, bst_left_2a, bst_right_2);

  ASSERT_EQUALS(lowestCommonAncestor(bst_2, bst_left_2a, bst_right_2), bst_2);
  ASSERT_EQUALS(lowestCommonAncestor(bst_2, bst_left_2a, bst_left_2b), bst_left_2a);
}
