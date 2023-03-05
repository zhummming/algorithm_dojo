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
    // https://leetcode.cn/problems/merge-k-sorted-lists/comments/641985  这是一个比较好的参考
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      auto dummy = new ListNode();
      auto p = dummy;

      // add elements to sorted, record first value and index for each list
      // 但其实不用记录索引吧，只需要记录指针就可以了吧？
      typedef int INDEX;
      typedef int VALUE;
      std::multimap<VALUE, INDEX> mapVI;
      for (auto iter = lists.begin(); iter != lists.end(); ++iter) {
        if (*iter) {
          auto vi = std::make_pair((*iter)->val, iter - lists.begin());
          mapVI.insert(vi);
        }
      }
      // traverse all lists, find least value from map, erase and add new from current list
      while (!mapVI.empty()) {
        auto curr_vi = mapVI.begin();
        auto index = curr_vi->second;
        p->next = lists[index];
        lists[index] = lists[index]->next;
        p = p->next;

        mapVI.erase(curr_vi);
        if (lists[index]) {
          auto new_vi = std::make_pair(lists[index]->val, index);
          mapVI.insert(new_vi);
        }
      }
      return dummy->next;
    }
};

int main(int argc, char **argv)
{
  std::vector<int> value1{1, 2, 5};
  std::vector<int> value2{1, 3, 4};
  std::vector<int> value3{2, 6};
  auto head1 = BuildLinkListWithoutHeadnode(value1);
  auto head2 = BuildLinkListWithoutHeadnode(value2);
  auto head3 = BuildLinkListWithoutHeadnode(value3);
  PrintLinkList(head1);
  PrintLinkList(head2);
  PrintLinkList(head3);
  vector<ListNode*> vl;
  vl.push_back(head1);
  vl.push_back(head2);
  vl.push_back(head3);

  Solution s;
  auto head = s.mergeKLists(vl);
  PrintLinkList(head);

  // std::multiset<int> is;
  // is.insert(2);
  // is.insert(1);
  // is.insert(0);
  // for (auto i : is) {
  //   cout << i << endl;
  // }
}