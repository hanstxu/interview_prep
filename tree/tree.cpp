#include "tree.h"

TreeNode::TreeNode() {
  this->value = 0;
  this->left = nullptr;
  this->right = nullptr;
}

TreeNode::TreeNode(int value) {
  this->value = value;
  this->left = nullptr;
  this->right = nullptr;
}

TreeNode::TreeNode(int value, TreeNode* left, TreeNode* right) {
  this->value = value;
  this->left = left;
  this->right = right;
}
