#include "common.hpp"

class Solution {
public:
  int depth = 0;
  int max_depth = 0;
  void traverse(TreeNode* root) {
    if (root == NULL) {
      return;
    }
    ++depth;
    // calculate when at leaf
    if (root->left == nullptr && root->right == nullptr) {
      max_depth = std::max(max_depth, depth);
    }
    traverse(root->left);
    traverse(root->right);
    --depth;
  }

  // path from root to farest leaf
  int maxDepth(TreeNode* root) {
    traverse(root);
    return max_depth;
  }

  // another recursive function by solve sub tree
  int maxDepthSub(TreeNode* root) {
      if (root == nullptr) {
          return 0;
      }

      int leftDepth = maxDepthSub(root->left);
      int rightDepth = maxDepthSub(root->right);

      return 1 + max(leftDepth, rightDepth);
  }
};

int main(int argc, char **argv)
{
  // build binary tree
  std::vector<int> values{1, 2, 3, 4, 5, 6, 7, 8};
  auto root = BuildBinaryTreeFromMiddle(values);
  PrintTreePreorder(root);

  Solution s;
  std::cout << "max depth: " << s.maxDepth(root) << std::endl;
}