#include "common.hpp"

// https://leetcode.cn/problems/reorder-list/
class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    // find shift count
    int size = 0;
    ListNode* p = head;
    while (p) {
      p = p->next;
      ++size;
    }
    int shift = size - k % size;
    if (shift == 0 || shift == size) {
      return head;
    }
    // move to shift pos
    p = head;
    while (--shift) {
      p = p->next;
    }
    // shift, modify pointer
    ListNode* prev = p;
    while(p->next) {
      p = p->next;
    }
    p->next = head;
    head = prev->next;
    prev->next = nullptr;
    return head;
  }
};

int main(int argc, char **argv)
{
  std::vector<int> value1{};
  auto head1 = BuildLinkListWithoutHeadnode(value1);
  PrintLinkList(head1);

  Solution s;
  auto head = s.rotateRight(head1, 1);
  PrintLinkList(head);
}