#include "common.hpp"

// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/
class Solution {
public:
    Node* connect(Node* root) {
      if (root == nullptr) {
        return nullptr;
      }
      traverse(root->left, root->right);
      return root;
    }

    void traverse(Node* node1, Node* node2) {
      if (node1 == nullptr || node2 == nullptr) {
        return;
      }
      
      node1->next = node2;
      traverse(node1->left, node1->right);
      traverse(node2->left, node2->right);
      traverse(node1->right, node2->left);
    }

    // another from leetcode
    void connect2(Node *root) {
        if (root == NULL || root->left == NULL)
            return;
        root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;  // 这一步是关键
        connect2(root->left);
        connect2(root->right);
    }
};

int main(int argc, char **argv)
{
  // build binary tree
  std::vector<int> values{1, 2, 3, 4, 5, 6, 7, 8};
  auto root = BuildNodeTreeFromMiddle(values);
  PrintNodeTreePreorder(root);

  std::cout << std::endl;
  Solution s;
  s.connect(root);
  PrintNodeTreePreorder(root);
}