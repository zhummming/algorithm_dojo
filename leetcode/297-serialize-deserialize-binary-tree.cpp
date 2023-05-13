#include "common.hpp"

// https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/
// thought: 通过前序遍历，对空指针特殊标识，然后进行序列话和反序列化
// 一个更简洁的写法： https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/comments/5690
class Solution {
public:
  const char kEmptyNode = '#';
  const char kDelimiter = ',';
  void traverse(TreeNode * root, std::string & data) {
    if (root == nullptr) {
      data += kEmptyNode;
      data += kDelimiter;
      return;
    }
    data += std::to_string(root->val);
    data += kDelimiter;
    traverse(root->left, data);
    traverse(root->right, data);
  }
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    std::string data;
    traverse(root, data);
    return data;
  }

  // Decodes your encoded data to tree.
  TreeNode* traverse(std::vector<std::string> & nodes, int & index) {
    // std::cout << "index: " << index << ", nodesize: "<< nodes.size() << std::endl;
    if (index >= nodes.size()) {
      return nullptr;
    }
    if (nodes[index] == "#") {
      ++index;
      return nullptr;
    }
    auto val = nodes[index];
    ++index;
    TreeNode * root = new TreeNode(std::stoi(val));
    // 给root的lr赋值，buildtree需要显式给left和right赋值
    root->left = traverse(nodes, index);  // 为了保持着两个地方的index一致，需要用引用才行
    root->right = traverse(nodes, index);
    return root;
  }
  TreeNode* deserialize(string data) {
    // 先解析数据到数组中，然后再去编译还原整棵树
    std::vector<std::string> nodes;
    std::stringstream ss(data);
    std::string item;
    while (std::getline(ss, item, ',')) {
      nodes.push_back(item);
    }
    int index = 0;
    auto r = traverse(nodes, index);
    return r;
  }
};

int main(int argc, char **argv)
{
  // build binary tree
  std::vector<int> values{1, 2, 3, 4, 5, 6, -7, 8};
  auto root = BuildBinaryTreeFromMiddle(values);
  PrintTreePreorder(root);
  std::cout << std::endl;

  Solution s;
  std::cout << s.serialize(root) << std::endl;
  auto root1 = s.deserialize(s.serialize(root));
  std::cout << "after serialize and deserialize: " << root1->val << std::endl;
  PrintTreePreorder(root1);
  std::cout << std::endl;
}