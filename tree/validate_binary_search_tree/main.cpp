#include "../../test.h"
#include "../tree.h"

#include <climits>
using namespace std;

/**
 * Given a binary tree, determine if it's a
 * binary search tree.
 */
bool isValidBinarySearchTree(TreeNode* root, long long min_bound, long long max_bound) {
  if (root == nullptr) {
    return true;
  }

  if (root->value <= min_bound || root->value >= max_bound) {
    return false;
  }

  return isValidBinarySearchTree(root->left, min_bound, root->value)
         && isValidBinarySearchTree(root->right, root->value, max_bound);
}

bool isValidBinarySearchTree(TreeNode* root) {
  return isValidBinarySearchTree(root, LLONG_MIN, LLONG_MAX);
}

int main() {
  TreeNode* empty_tree = nullptr;
  ASSERT_TRUE(isValidBinarySearchTree(empty_tree));

  TreeNode* tree_1 = new TreeNode(5);
  ASSERT_TRUE(isValidBinarySearchTree(tree_1));

  TreeNode* tree_2 = new TreeNode(5, new TreeNode(3), new TreeNode(7));
  ASSERT_TRUE(isValidBinarySearchTree(tree_2));

  TreeNode* tree_3 = new TreeNode(5, new TreeNode(6), new TreeNode(7));
  ASSERT_FALSE(isValidBinarySearchTree(tree_3));

  TreeNode* tree_4 = new TreeNode(5, new TreeNode(3), new TreeNode(4));
  ASSERT_FALSE(isValidBinarySearchTree(tree_4));

  TreeNode* tree_5 = new TreeNode(5,
                                  new TreeNode(2),
                                  new TreeNode(8, new TreeNode(3), new TreeNode(10)));
  ASSERT_FALSE(isValidBinarySearchTree(tree_5));

  TreeNode* tree_6 = new TreeNode(2, new TreeNode(2), new TreeNode(3));
  ASSERT_FALSE(isValidBinarySearchTree(tree_6));

  TreeNode* tree_7 = new TreeNode(2, new TreeNode(3), new TreeNode(2));
  ASSERT_FALSE(isValidBinarySearchTree(tree_7));

  TreeNode* tree_8 = new TreeNode(INT_MAX);
  ASSERT_TRUE(isValidBinarySearchTree(tree_8));

  TreeNode* tree_9 = new TreeNode(INT_MIN);
  ASSERT_TRUE(isValidBinarySearchTree(tree_9));
}
