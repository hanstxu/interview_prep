#include "../../test.h"
#include "../tree.h"

#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Given a preorder and inorder traversal of a binary tree,
 * construct the binary tree.
 *
 * Condition that all values in the binary tree are unique.
 * This allows for optimization on the finding the pivot value
 * using a hash table.
 */

int findPivot(unordered_map<int, int>& inorder_lookup_table, int value) {
  return inorder_lookup_table[value];
}

TreeNode* buildTree(
  vector<int>& preorder,
  vector<int>& inorder,
  int& root_index,
  int left,
  int right,
  unordered_map<int, int>& inorder_lookup_table)
{
  if (left > right) {
    return nullptr;
  }

  int pivot = findPivot(inorder_lookup_table, preorder[root_index]);

  TreeNode* root = new TreeNode(preorder[root_index]);
  root_index++;

  root->left = buildTree(preorder, inorder, root_index, left, pivot - 1, inorder_lookup_table);
  root->right = buildTree(preorder, inorder, root_index, pivot + 1, right, inorder_lookup_table);

  return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  unordered_map<int, int> inorder_lookup_table;
  for (int i = 0; i < inorder.size(); ++i) {
    inorder_lookup_table[inorder[i]] = i;
  }

  int root_index = 0;
  return buildTree(preorder, inorder, root_index, 0, preorder.size() - 1, inorder_lookup_table);
}

int main() {
  vector<int> empty_list;
  ASSERT_EQUALS(buildTree(empty_list, empty_list), nullptr);

  vector<int> preorder_1 = {1};
  vector<int> inorder_1 = {1};
  ASSERT_EQUALS(buildTree(preorder_1, inorder_1), new TreeNode(1));

  vector<int> preorder_2 = {1,2,4,5,3};
  vector<int> inorder_2 = {4,2,5,1,3};
  ASSERT_EQUALS(buildTree(preorder_2, inorder_2),
                new TreeNode(1,
                             new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                             new TreeNode(3)));

  vector<int> preorder_3 = {3,9,20,15,7};
  vector<int> inorder_3 = {9,3,15,20,7};
  ASSERT_EQUALS(buildTree(preorder_3, inorder_3),
                new TreeNode(3,
                             new TreeNode(9),
                             new TreeNode(20, new TreeNode(15), new TreeNode(7))));
}
