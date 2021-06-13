#include "../../test.h"
#include "../tree.h"
using namespace std;

/**
 * Given two binary trees, determine if one tree
 * is the subtree of another tree.
 *
 * Note that the inputs will not include null trees.
 */
bool isSame(TreeNode* root1, TreeNode* root2) {
  if (root1 == nullptr && root2 == nullptr) {
    return true;
  }

  if (root1 == nullptr || root2 == nullptr) {
    return false;
  }

  if (root1->value != root2->value) {
    return false;
  }

  return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
  if (root == nullptr) {
    return false;
  }

  if (isSame(root, subRoot)) {
    return true;
  }

  return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
  ASSERT_FALSE(isSubtree(nullptr, new TreeNode(1)));

  TreeNode* tree = new TreeNode(
    3,
    new TreeNode(4, new TreeNode(1), new TreeNode(2)),
    new TreeNode(5));

  TreeNode* subtree_1 = new TreeNode(4, new TreeNode(1), new TreeNode(2));
  ASSERT_TRUE(isSubtree(tree, subtree_1));

  TreeNode* subtree_2 = new TreeNode(4, new TreeNode(2), new TreeNode(1));
  ASSERT_FALSE(isSubtree(tree, subtree_2));

  TreeNode* subtree_3 = new TreeNode(1);
  ASSERT_TRUE(isSubtree(tree, subtree_3));
}
