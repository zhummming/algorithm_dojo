#include "common.hpp"

// https://leetcode.cn/problems/find-duplicate-subtrees/
// thought: 依然是序列化的思路，只不过放在后序的位置。解法参考： https://leetcode.cn/problems/find-duplicate-subtrees/comments/58714
class Solution {
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    std::unordered_map<std::string, int> subtree_times;
    std::vector<TreeNode*> result;
    helper(root, subtree_times, result);
    return result;
  }

  std::string helper(TreeNode* root, std::unordered_map<std::string, int> & subtree_times, std::vector<TreeNode*> & result) {
    if (root == nullptr) {
      return "#";
    }
    // nodes之间需要有空格，不然对于 11 1， 1 11这两组，就都变成了111而一样了
    std::string str = std::to_string(root->val) + ' ' + helper(root->left, subtree_times, result) + ' ' + helper(root->right, subtree_times, result);
    // 如下是从叶子结点开始形成的子树，从后往前推进
    if (subtree_times[str] == 1) {
      result.push_back(root);
    }
    subtree_times[str]++;
    return str;
  }
};

int main(int argc, char **argv)
{
  // build binary tree
  std::vector<int> values{1, 2, 3, 4, 5, 6, -7, 1};
  auto root = BuildBinaryTreeFromMiddle(values);
  PrintTreePreorder(root);
  std::cout << std::endl;

  Solution s;
  auto result = s.findDuplicateSubtrees(root);
  for (auto r : result) {
    PrintTreePreorder(r);
    std::cout << std::endl;
  }
}