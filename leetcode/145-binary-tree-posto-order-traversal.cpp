#include "common.hpp"

// https://leetcode.cn/problems/binary-tree-level-order-traversal/
class Solution {
public:
  vector<int> post;
  vector<int> postorderTraversalRecursive(TreeNode* root) {
    if (root == nullptr) {
      return vector<int>();
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    post.push_back(root->val);
    return post;
  }
  vector<int> postorderTraversal(TreeNode* root) {
    TreeNode * p = root, * r = nullptr;
    std::stack<TreeNode*> s;
    std::vector<int> res;
    // add data to post
    while(p || !s.empty()) {
      if (p) {
        s.push(p);
        p = p->left;
      } else {
        p = s.top();
        // r记录了上一次弹出的节点，如果上次弹出的节点是当前节点是right，就表明当前节点是第二次被遍历了，应当弹出
        if (p->right == nullptr || p->right == r) {
          res.push_back(p->val);
          r = p;
          s.pop();
          p = nullptr;
        } else {
          // 当前节点有right，并且是第一次被遍历，则访问right
          p = p->right;
        }
      }
    }
    return res;
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
  // auto result1 = s.postorderTraversal(root);
  // for (auto r : result1) {
  //   std::cout << r << " ";
  // }
  // std::cout << std::endl;
  auto result2 = s.postorderTraversalNoRecursive(root);
  for (auto r : result2) {
    std::cout << r << " ";
  }
  std::cout << std::endl;
}