#ifndef TREE_H
#define TREE_H

#include <iostream>

class TreeNode {
public:
  int value;
  TreeNode* left;
  TreeNode* right;

  TreeNode();
  TreeNode(int x);
  TreeNode(int x, TreeNode* left, TreeNode* right);
};

void assertEquals(TreeNode* actual, TreeNode* expected, std::string file, int line);

#endif
