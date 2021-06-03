#include "../../test.h"
#include "../tree.h"

/**
 * Given the roots of two binary trees, determine
 * if they are the same or not.
 */
bool isSameTree(TreeNode* p, TreeNode* q) {
  if (p == nullptr && q == nullptr) {
    return true;
  }

  if (p == nullptr) {
    return false;
  }

  if (q == nullptr) {
    return false;
  }

  if (p->value != q-> value) {
    return false;
  }

  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
  TreeNode* empty_tree = nullptr;
  TreeNode* single_node = new TreeNode(5);
  ASSERT_TRUE(isSameTree(empty_tree, nullptr));
  ASSERT_FALSE(isSameTree(single_node, empty_tree));
  ASSERT_FALSE(isSameTree(empty_tree, single_node));
  ASSERT_TRUE(isSameTree(single_node, new TreeNode(5)));

  TreeNode* input1_p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode* input1_q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  ASSERT_TRUE(isSameTree(input1_p, input1_q));

  TreeNode* input2_p = new TreeNode(1, new TreeNode(2), nullptr);
  TreeNode* input2_q = new TreeNode(1, nullptr, new TreeNode(2));
  ASSERT_FALSE(isSameTree(input2_p, input2_q));

  TreeNode* input3_p = new TreeNode(1, new TreeNode(2), new TreeNode(1));
  TreeNode* input3_q = new TreeNode(1, new TreeNode(1), new TreeNode(2));
  ASSERT_FALSE(isSameTree(input3_p, input3_q));
}
