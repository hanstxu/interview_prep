#include "../../test.h"
#include "../tree.h"

#include <sstream>
#include <string>
#include <iostream>
using namespace std;

/**
 * Design an algorithm to serialize and deserialize a binary tree.
 */
class Codec {
private:
  void serialize(TreeNode* root, ostringstream& out) {
    if (root) {
      out << root->value << ' ';
      serialize(root->left, out);
      serialize(root->right, out);

    } else {
      out << "# ";
    }
  }

  TreeNode* deserialize(istringstream& in) {
    string value;
    in >> value;

    if (value == "#") {
      return nullptr;
    }

    TreeNode* node = new TreeNode(stoi(value));
    node->left = deserialize(in);
    node->right = deserialize(in);

    return node;
  }

public:
  string serialize(TreeNode* root) {
    ostringstream out;
    serialize(root, out);
    return out.str();
  }

  TreeNode* deserialize(string data) {
    istringstream in(data);
    return deserialize(in);
  }
};

int main() {
  Codec codec;

  TreeNode* empty_tree = nullptr;
  ASSERT_EQUALS(codec.serialize(empty_tree), "# ");

  TreeNode* tree_1 = new TreeNode(5);
  ASSERT_EQUALS(codec.serialize(tree_1), "5 # # ");

  TreeNode* tree_2 = new TreeNode(5, new TreeNode(3), new TreeNode(4));
  ASSERT_EQUALS(codec.serialize(tree_2), "5 3 # # 4 # # ");

  TreeNode* tree_3 = new TreeNode(5, nullptr, new TreeNode(2, nullptr, new TreeNode(1)));
  ASSERT_EQUALS(codec.serialize(tree_3), "5 # 2 # 1 # # ");

  TreeNode* tree_4 = new TreeNode(
    1,
    new TreeNode(2),
    new TreeNode(3, new TreeNode(4), new TreeNode(5)));
  ASSERT_EQUALS(codec.serialize(tree_4), "1 2 # # 3 4 # # 5 # # ");

  ASSERT_EQUALS(codec.deserialize("# "), empty_tree);
  ASSERT_EQUALS(codec.deserialize("5 # # "), tree_1);
  ASSERT_EQUALS(codec.deserialize("5 3 # # 4 # # "), tree_2);
  ASSERT_EQUALS(codec.deserialize("5 # 2 # 1 # # "), tree_3);
  ASSERT_EQUALS(codec.deserialize("1 2 # # 3 4 # # 5 # # "), tree_4);

  ASSERT_EQUALS(codec.deserialize(codec.serialize(empty_tree)), empty_tree);
  ASSERT_EQUALS(codec.deserialize(codec.serialize(tree_1)), tree_1);
  ASSERT_EQUALS(codec.deserialize(codec.serialize(tree_2)), tree_2);
  ASSERT_EQUALS(codec.deserialize(codec.serialize(tree_3)), tree_3);
  ASSERT_EQUALS(codec.deserialize(codec.serialize(tree_4)), tree_4);
}
