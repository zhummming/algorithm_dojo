#include "common.hpp"

// https://leetcode.cn/problems/partition-list/
class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    // if create new list
    ListNode* dummy1 = new ListNode(-1);
    ListNode* dummy2 = new ListNode(-1);
    // 其实最好是写成局部变量，ListNode dummy1; 自动释放即可
    auto p1 = dummy1, p2 = dummy2;
    auto p = head;
    while(p) {
      if (p->val < x) {
        p1->next = p;
        p1 = p1->next;
      } else {
        p2->next = p;
        p2 = p2->next;
      }
      p = p->next;
    }
    p1->next = dummy2->next;
    p2->next = nullptr;  // not necessary
    auto res = dummy1->next;
    delete dummy1;
    delete dummy2;
    return res;
  }
};

int main(int argc, char **argv)
{
  std::vector<int> value{1,4,3,2,5,2};
  auto head = BuildLinkListWithoutHeadnode(value);
  PrintLinkList(head);

  Solution s;
  auto head1 = s.partition(head, 3);
  PrintLinkList(head1);
}