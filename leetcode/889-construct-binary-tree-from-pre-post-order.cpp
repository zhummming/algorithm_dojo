#include "common.hpp"

// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
// thought: 由于左右子树不唯一，所以此处构造出来的二叉树不是唯一的
class Solution {
public:
  TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
  }
  // s&e is first and last index of array
  TreeNode* build(vector<int>& preorder, int s1, int e1, vector<int>& postorder, int s2, int e2) {
    if (s1 > e1) {
      return nullptr;
    }
    if (s1 == e1) {
      return new TreeNode(preorder[s1]);
    }

    // construct root，根据前序左子树第一个元素，作为左子树根节点，来去确定后序中left tree的大小
    int val = preorder[s1];
    int left_val = preorder[s1 + 1];
    int index = 0;
    for (int i = s2; i <= e2; i++) {
      if (left_val == postorder[i]) {
        index = i;
        break;
      }
    }
    int left_len = index - s2 + 1;  // 注意此处要+1，因为此时的index是属于left的
    // std::cout << "val: " << val << "index: " << index << std::endl;
    TreeNode* root = new TreeNode(val);
    root->left = build(preorder, s1 + 1, s1 + left_len, postorder, s2, index);
    root->right = build(preorder, s1 + left_len + 1, e1, postorder, index + 1, e2 - 1);
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
  PrintTreePreorder(root);
  std::cout << std::endl;

  std::vector<int> pre{5, 3, 2, 1, 4, 7, 6, 8};
  std::vector<int> in{1, 2, 3, 4, 5, 6, 7, 8};
  std::vector<int> post{1, 2, 4, 3, 6, 8, 7, 5};
  // std::vector<int> pre{3,9,20,15,7};
  // std::vector<int> in{9,3,15,20,7};
  
  Solution s;
  auto tree = s.constructFromPrePost(pre, post);
  PrintTreePostorder(tree);
  std::cout << std::endl;
  PrintTreePreorder(tree);
}