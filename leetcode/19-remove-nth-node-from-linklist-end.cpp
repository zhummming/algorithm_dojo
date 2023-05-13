#include "common.hpp"

// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      // first move one point to nth, use n-- to move n times
      auto p1 = head;
      while (p1 && n--) {
        p1 = p1->next;
        // cout << "move p: " << n << endl;
      }
      // if p1 is nullptr but n > 0, means n is invalid and bigger than size of head
      if (n > 0) {
        return nullptr;
      }
      if (!p1) {
        // delete head
        // cout << "delete head: " << head->val << endl;
        auto p = head;
        head = head->next;
        delete p;
      } else {
        // then use two point to find (n+1)th to end
        auto p2 = head;
        while (p1->next) {
          p1 = p1->next;
          p2 = p2->next;
        }
        // then remove this point: p2->next
        auto nth_node = p2->next;
        p2->next = nth_node->next;
        // cout << "delete nth: " << nth_node->val << endl;
        delete nth_node;
      }
      return head;

      // 自己的方法写的太复杂太乱了,这个方法更加简洁！
      // if(!head | !head -> next) return NULL;
      // ListNode * fast = head, *slow = head;
      // for(int i = 0; i < n; i++){
      //     fast = fast -> next;
      // }
      // if(!fast){
      //     return head -> next;    
      // }
      
      // while(fast -> next){
      //     fast = fast -> next;
      //     slow = slow -> next;
      // }
      // 因为是删除最后N个节点，所以要到最后的
      // slow -> next = slow -> next -> next;
      // return head;
    }
};

int main(int argc, char **argv)
{
  std::vector<int> value{1};
  auto head = BuildLinkListWithoutHeadnode(value);
  PrintLinkList(head);

  Solution s;
  auto head1 = s.removeNthFromEnd(head, 2);
  PrintLinkList(head1);
}