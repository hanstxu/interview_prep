#include "tree.h"
#include <iostream>
#include <queue>

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

void assertEquals(TreeNode* actual, TreeNode* expected, std::string file, int line) {
  if (actual == nullptr && expected == nullptr) {
    return;
  }

  if (actual == nullptr || expected == nullptr) {
    std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
              << " in " << file << std::endl;
    return;
  }

  std::queue<TreeNode*> binary_tree_queue;
  binary_tree_queue.push(actual);
  binary_tree_queue.push(expected);

  while (!binary_tree_queue.empty()) {
    TreeNode* first_node = binary_tree_queue.front();
    binary_tree_queue.pop();

    TreeNode* second_node = binary_tree_queue.front();
    binary_tree_queue.pop();

    if (first_node->value != second_node->value) {
      std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
                << " in " << file << std::endl;
      break;
    }

    if (first_node->left != nullptr && second_node->left != nullptr) {
      binary_tree_queue.push(first_node->left);
      binary_tree_queue.push(second_node->left);

    } else if (!(first_node->left == nullptr && second_node->left == nullptr)) {
      std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
                << " in " << file << std::endl;
      break;
    }

    if (first_node->right != nullptr && second_node->right != nullptr) {
      binary_tree_queue.push(first_node->right);
      binary_tree_queue.push(second_node->right);

    } else if (!(first_node->right == nullptr && second_node->right == nullptr)) {
      std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
                << " in " << file << std::endl;
      break;
    }
  }
}
