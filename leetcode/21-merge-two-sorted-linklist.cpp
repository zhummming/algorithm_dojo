#include "common.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 迭代解法
        auto dummy = new ListNode();
        auto p = dummy;
        while (list1 && list2) {
          if (list1->val <= list2->val) {
            p->next = list1;
            list1 = list1->next;
          } else {
            p->next = list2;
            list2 = list2->next;
          }
          p = p->next;  // keep moving p
        }
        if (list1) {
          p->next = list1;
        } else {
          p->next = list2;
          // if create new node
          // while (list2) {
          //   p->next = new ListNode(list2->val);
          //   p = p->next;
          //   list2 = list2->next;
          // }
        }
        return dummy->next;
    }

    ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2) {
        if (!list1) {
          return list2;
        }
        if (!list2) {
          return list1;
        }

        if (list1->val <= list2->val) {
          list1->next = mergeTwoListsRecursive(list1->next, list2);
          return list1;
        } else {
          list2->next = mergeTwoListsRecursive(list1, list2->next);
          return list2;
        }
    }
};

int main(int argc, char **argv)
{
  std::vector<int> value1{1, 2, 4};
  std::vector<int> value2{0, 3, 5};
  auto head1 = BuildLinkListWithoutHeadnode(value1);
  auto head2 = BuildLinkListWithoutHeadnode(value2);
  PrintLinkList(head1);
  PrintLinkList(head2);

  Solution s;
  auto head = s.mergeTwoListsRecursive(head1, head2);
  // auto head = s.mergeTwoLists(head1, head2);
  PrintLinkList(head);
}