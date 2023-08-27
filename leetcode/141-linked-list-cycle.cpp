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
      ListNode* fast = head;
      ListNode* slow = head;
      // fast一定比slow先到nullptr，所以检查fast就够了
      while(fast != NULL && fast->next != NULL) {
          slow = slow->next;
          fast = fast->next->next;
          // 快慢指针相遇，说明有环
          if (slow == fast) return true;
      }
      return false;
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