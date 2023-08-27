#include "common.hpp"

// https://leetcode.cn/problems/reorder-list/
class Solution {
public:
  ListNode* reverseList1(ListNode* head) {
    std::stack<ListNode*> s;
    auto p = head;
    while(p) {
      s.push(p);
      p = p->next;
    }
    if (!s.empty()) {
      head = s.top();
      s.pop();
      p = head;
      while(!s.empty()) {
        p->next = s.top();
        p = p->next;
        s.pop();
      }
      p->next = nullptr;
    }
    // p->next = nullptr; // 如果放在这里，传入空链表的时候，会报错
    return head;
    // attention, modify last pointer to null!
  }
  ListNode* reorderListRecursive(ListNode* prev, ListNode* curr) {
    if (curr->next == nullptr) {
      // last node, point to prev
      curr->next = prev;
      // todo: segment fault here, recursive failed!
      return curr;
    }
    // std::cout << prev->val << " " << curr->val << std::endl;
    auto tail = reorderListRecursive(curr, curr->next);
    curr->next = prev;
    return tail;
  }
  ListNode* reverseList2(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    auto tail = reorderListRecursive(head, head->next);
    head->next = nullptr;
    return tail;
  }

  // double pointer
  ListNode* reverseList3(ListNode* head) {
    ListNode * prev = nullptr, * curr = head;
    ListNode * temp = nullptr;
    while (curr != nullptr) {
      temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }
    return prev;
  }
};

int main(int argc, char **argv)
{
  std::vector<int> value1{};
  auto head1 = BuildLinkListWithoutHeadnode(value1);
  PrintLinkList(head1);

  Solution s;
  auto head = s.reverseList3(head1);  // here, head1->next = nullptr, head->next is valid
  PrintLinkList(head);
}