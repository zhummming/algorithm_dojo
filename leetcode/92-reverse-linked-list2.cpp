#include "common.hpp"

// https://leetcode.cn/problems/reorder-list/
class Solution {
public:
  // double pointer
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (head == nullptr || left >= right) {
      return head;
    }
    ListNode * prev = nullptr, * curr = head;
    int n = left;
    while (--n) {
      prev = curr;
      curr = curr->next;
    }
    ListNode * head1 = prev;
    ListNode * tail1 = curr;
    ListNode * tail2 = curr;
    // // move pointer first
    // prev = curr;
    // curr = curr->next;
    n = right - left + 1;
    ListNode * temp = nullptr;
    while (n--) {
      temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
      if (0 == n) {
        tail2 = temp;
      }
    }
    // empty linklist will access nullptr
    if (head1) {
      head1->next = prev;
    } else {
      head = prev;
    }
    if (tail1) {
      tail1->next = tail2;
    }
    return head;  // head may change
  }
};

int main(int argc, char **argv)
{
  std::vector<int> value1{3,5};
  auto head1 = BuildLinkListWithoutHeadnode(value1);
  PrintLinkList(head1);

  Solution s;
  auto head = s.reverseBetween(head1,1,2);  // here, head1->next = nullptr, head->next is valid
  PrintLinkList(head);
}