#include "common.hpp"

class Solution {
public:
  int diameter = 0;
  int maxDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }

    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);

    // 需要取左右最大深度，取更大的作为直径的大小
    diameter = std::max(left_depth + right_depth, diameter);
    return 1 + std::max(left_depth, right_depth);
  }

  // length of the longest path(nodes-1) between any two nodes in a tree
  int diameterOfBinaryTree(TreeNode* root) {
    maxDepth(root);
    return diameter;
  }
};

int main(int argc, char **argv)
{
  // build binary tree
  std::vector<int> values{1, 2, 3, 4, 5, 6, 7, 8};
  auto root = BuildBinaryTreeFromMiddle(values);
  PrintTreePreorder(root);

  Solution s;
  std::cout << "diameter: " << s.diameterOfBinaryTree(root) << std::endl;
}