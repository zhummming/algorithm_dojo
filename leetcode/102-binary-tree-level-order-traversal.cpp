#include "common.hpp"

// https://leetcode.cn/problems/binary-tree-level-order-traversal/
class Solution {
public:
  vector<vector<int>> result;
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) {
      return std::vector<vector<int>>();
    }

    std::queue<TreeNode*> level_nodes;
    level_nodes.push(root);
    while (!level_nodes.empty()) {
      int curr_node_count = level_nodes.size();  // 这里的curr_node_count很关键，决定了第二层循环的次数
      std::vector<int> curr_level_val;
      while (curr_node_count > 0) {
        auto node = level_nodes.front();
        level_nodes.pop();
        --curr_node_count;
        
        curr_level_val.push_back(node->val);
        if (node->left) {
          level_nodes.push(node->left);
        }
        if (node->right) {
          level_nodes.push(node->right);  // 错写成了root->right??????????????好低级的错误啊！！！
        }
      }
      result.push_back(curr_level_val);
    }
    return result;
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
  auto result = s.levelOrder(root);
  for (auto r : result) {
    for (auto node : r) {
      std::cout << node << " ";
    }
    std::cout << std::endl;
  }
}