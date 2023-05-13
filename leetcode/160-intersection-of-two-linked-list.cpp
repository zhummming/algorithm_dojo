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
    // A->B, B->A，合并
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p1 = headA;
        auto p2 = headB;
        bool endA = false;
        bool endB = false;
        while (p1 && p2) {
          if (p1 == p2) {
            return p1;
          }
          p1 = p1->next;
          p2 = p2->next;
          if (!endA && !p1) {
            p1 = headB;
            endA = true;
          }
          if (!endB && !p2) {
            p2 = headA;
            endB = true;
          }
        }
        return nullptr;

        // 以上的写法过于冗余，其实没有必要用endA和endB，因为二者最终肯定是同时到达null，参考如下写法：https://leetcode.cn/problems/intersection-of-two-linked-lists/comments/3107
        // if(headA == null || headB == null) return null;
        // ListNode pA = headA, pB = headB;
        // // 在这里第一轮体现在pA和pB第一次到达尾部会移向另一链表的表头, 而第二轮体现在如果pA或pB相交就返回交点, 不相交最后就是null==null
        // while(pA != pB) {
        //     pA = pA == null ? headB : pA.next;
        //     pB = pB == null ? headA : pB.next;
        // }
        // return pA;
    }
};

int main(int argc, char **argv)
{
  std::vector<int> value1{3, 2, 0, -4};
  std::vector<int> value2{1, 3, 2, 0, -4};
  auto node_pair = BuildIntersectLinkList(value1, 1, value2, 2);
  PrintLinkList(node_pair.first);
  PrintLinkList(node_pair.second);

  Solution s;
  std::cout << s.getIntersectionNode(node_pair.first, node_pair.second)->val << std::endl;
}