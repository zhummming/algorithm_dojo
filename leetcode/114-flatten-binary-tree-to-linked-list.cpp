#include "common.hpp"

// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/flatten-binary-tree-to-linked-list
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// thought: 原地拉平，不能构建新的链表。可以用递归的方法，在左右分别拉平之后，将左子树挪到右边，然后右子树接到最后。后序位置做的就是这个操作
class Solution {
public:
  void flatten(TreeNode* root) {
    if (root == nullptr) {
      return;
    }

    flatten(root->left);
    flatten(root->right);

    auto right = root->right;
    auto left = root->left;
    auto p = root;
    while (left) {
      p->right = left;
      p = p->right;
      left = left->right;  // left has been flatten, so left node has no left sub tree, only right subtree
    }
    p->right = right;
    root->left = nullptr;
  }

  // thought: last记录flatten右子树，没错root到了一个新节点，就把这个last作为左子树给到root，于是有了一个从后往前的操作。注意要先递归right，确保先到最后一个节点
  // 8 
  // 6 8 
  // 7 6 8 
  // 4 7 6 8 
  // 1 4 7 6 8 
  // 2 1 4 7 6 8 
  // 3 2 1 4 7 6 8 
  // 5 3 2 1 4 7 6 8 
  TreeNode* last = nullptr;
  void flatten2(TreeNode* root) {
      if (root == nullptr) return;
      flatten2(root->right);
      flatten2(root->left);
      root->right = last;
      root->left = nullptr;
      last = root;
      // test only
      PrintTreePreorder(last);
      std::cout << std::endl;
  }
};

int main(int argc, char **argv)
{
  // build binary tree
  std::vector<int> values{1, 2, 3, 4, 5, 6, 7, 8};
  auto root = BuildBinaryTreeFromMiddle(values);
  PrintTreePreorder(root);

  std::cout << std::endl;
  Solution s;
  s.flatten2(root);
  PrintTreePreorder(root);
}