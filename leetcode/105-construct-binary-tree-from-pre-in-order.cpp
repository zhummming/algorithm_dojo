#include "common.hpp"

// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
  }
  // s&e is first and last index of array
  TreeNode* build(vector<int>& preorder, int s1, int e1, vector<int>& inorder, int s2, int e2) {
    if (s1 > e1) {
      return nullptr;
    }

    // construct root
    int val = preorder[s1];
    int index = 0;
    for (int i = s2; i <= e2; i++) {
      if (val == inorder[i]) {
        index = i;
        break;
      }
    }
    int left_len = index - s2;
    std::cout << "val: " << val << "index: " << index << std::endl;
    TreeNode* root = new TreeNode(val);
    root->left = build(preorder, s1 + 1, s1 + left_len, inorder, s2, index - 1);
    root->right = build(preorder, s1 + left_len + 1, e1, inorder, index + 1, e2);
    return root;  // should return root!
  }
};

int main(int argc, char **argv)
{
  // build binary tree
  std::vector<int> values{1, 2, 3, 4, 5, 6, 7, 8};
  auto root = BuildBinaryTreeFromMiddle(values);
  PrintTreePreorder(root);
  std::cout << std::endl;
  PrintTreeInorder(root);

  std::vector<int> pre{5, 3, 2, 1, 4, 7, 6, 8};
  std::vector<int> in{1, 2, 3, 4, 5, 6, 7, 8};
  // std::vector<int> pre{3,9,20,15,7};
  // std::vector<int> in{9,3,15,20,7};
  
  Solution s;
  auto tree = s.buildTree(pre, in);
  PrintTreePreorder(tree);
  std::cout << std::endl;
  PrintTreeInorder(tree);
}