/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "common.hpp"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto p1 = head;
        auto p2 = head;
        while (p1 && p2) {
          p1 = p1->next;
          // p2 = p2->next->next;  // check if p2 is null
          p2 = p2->next;
          if (!p2) {
            return false;
          }
          p2 = p2->next;
          if (p1 == p2) {
            return true;
          }
        }
        return false;

        /// below is a better and clear version: https://leetcode.cn/problems/linked-list-cycle/comments/1149448
        // ListNode* fast = head;
        // ListNode* slow = head;
        // while(fast != NULL && fast->next != NULL) {
        //     slow = slow->next;
        //     fast = fast->next->next;
        //     // 快慢指针相遇，说明有环
        //     if (slow == fast) return true;
        // }
        // return false;
    }
};

int main(int argc, char **argv)
{
  std::vector<int> value {1, 2, 3, 4, 5, 6, 7};
  // auto head = BuildLinkList(value);
  // PrintLinkList(head);
  // Solution s;
  // std::cout << s.hasCycle(head) << std::endl;

  auto head = BuildCycleLinkList(value, 4);
  PrintCycleLinkList(head);
  Solution s;
  std::cout << s.hasCycle(head) << std::endl;
}