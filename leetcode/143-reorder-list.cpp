#include "common.hpp"

// https://leetcode.cn/problems/reorder-list/
class Solution {
public:
  void reorderList(ListNode* head) {
    std::stack<ListNode*> s;
    auto p = head->next;
    while(p) {
      s.push(p);
      p = p->next;
    }
    p = head;
    while(!s.empty()) {
      p->next = s.top();
      p = p->next;
      s.pop();
    }
    p->next = nullptr;
    // attention, modify last pointer to null!
  }
  ListNode* reorderListRecursive(ListNode* prev, ListNode* curr) {
    if (curr->next == nullptr) {
      // last node, point to prev
      cout << "return: " << endl;
      std::cout << prev->val << " " << curr->val << std::endl;
      curr->next = prev;
      cout << "before return: " << endl;
      // todo: segment fault here, recursive failed!
      return curr;
    }
    std::cout << prev->val << " " << curr->val << std::endl;
    auto tail = reorderListRecursive(curr, curr->next);
    curr->next = prev;
    return tail;
  }
  void reorderList1(ListNode* head) {
    auto tail = reorderListRecursive(head, head->next);
    head->next->next = nullptr;
    head->next = tail;
  }
};

int main(int argc, char **argv)
{
  std::vector<int> value1{1, 2, 5, 6};
  auto head1 = BuildLinkListWithoutHeadnode(value1);
  PrintLinkList(head1);

  Solution s;
  s.reorderList1(head1);
  PrintLinkList(head1);
}