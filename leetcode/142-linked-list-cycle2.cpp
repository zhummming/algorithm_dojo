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
    ListNode *detectCycle(ListNode *head) {
        auto fast = head;
        auto slow = head;
        while(fast && fast->next) {
          slow = slow->next;
          fast = fast->next->next;
          // cycle exist, find loop point
          if (slow == fast) {
            slow = head;
            while (slow != fast) {
              slow = slow->next;
              fast = fast->next;
            }
            return slow;
          }
        }
        return nullptr;
    }

    // below is a more efficient and tricky way, with O(n): https://leetcode.cn/problems/linked-list-cycle-ii/comments/37475
    // 链表内存是递增的的，因此next一定大于current，除非是有环了，而此时就是tail和环起点的关系
    ListNode *detectCycle1(ListNode *head) {
        while(head) {
            if(!less<ListNode *>()(head, head->next)) {
                return head->next;
            }
            head = head->next;
        }
        return nullptr;
    }

    // 另一个思路则是通过遍历所有node的地址，找到重复的地址就可以认为是有环了，这个跟我在common.hpp中的PrintCycleLinkList类似
    // java implementation: https://leetcode.cn/problems/linked-list-cycle-ii/comments/1630058
    // public ListNode detectCycle(ListNode head) {
    //     HashSet<ListNode> hashSet=new HashSet<>();
    //     ListNode cur=new ListNode(0);
    //     cur.next=head;
        
    //     while(hashSet.add(cur)!=false){
    //         if(cur==null){
    //             return null;
    //         }
    //         cur=cur.next;
    //     }
        
    //     return cur;
    // }
};

int main(int argc, char **argv)
{
  std::vector<int> value {3, 2, 0, -4};
  // auto head = BuildLinkList(value);
  // PrintLinkList(head);
  // Solution s;
  // std::cout << s.hasCycle(head) << std::endl;

  auto head = BuildCycleLinkList(value, 2);
  PrintCycleLinkList(head);
  Solution s;
  std::cout << s.detectCycle(head)->val << std::endl;
}