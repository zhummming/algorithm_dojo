#include "common.hpp"

// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// thought: 原地拉平，不能构建新的链表。可以用递归的方法，在左右分别拉平之后，将左子树挪到右边，然后右子树接到最后。后序位置做的就是这个操作
class Solution {
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return build(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
  }
  // s&e is first and last index of array
  TreeNode* build(vector<int>& postorder, int s1, int e1, vector<int>& inorder, int s2, int e2) {
    if (s1 > e1) {
      return nullptr;
    }

    // construct root
    int val = postorder[e1];
    int index = 0;
    for (int i = s2; i <= e2; i++) {
      if (val == inorder[i]) {
        index = i;
        break;
      }
    }
    int left_len = index - s2;
    // std::cout << "val: " << val << "index: " << index << std::endl;
    TreeNode* root = new TreeNode(val);
    root->left = build(postorder, s1, s1 + left_len - 1, inorder, s2, index - 1);
    root->right = build(postorder, s1 + left_len, e1 - 1, inorder, index + 1, e2);
    return root;  // should return root!
  }
};

int main(int argc, char **argv)
{
  // build binary tree
  std::vector<int> values{1, 2, 3, 4, 5, 6, 7, 8};
  auto root = BuildBinaryTreeFromMiddle(values);
  PrintTreePostorder(root);
  std::cout << std::endl;
  PrintTreeInorder(root);

  std::vector<int> in{1, 2, 3, 4, 5, 6, 7, 8};
  std::vector<int> post{1, 2, 4, 3, 6, 8, 7, 5};
  // std::vector<int> pre{3,9,20,15,7};
  // std::vector<int> in{9,3,15,20,7};
  
  Solution s;
  auto tree = s.buildTree(in, post);
  PrintTreePostorder(tree);
  std::cout << std::endl;
  PrintTreeInorder(tree);
}