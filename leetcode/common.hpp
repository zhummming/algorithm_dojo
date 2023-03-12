#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <utility>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* BuildLinkList(std::vector<int> values) {
  ListNode* head = new ListNode(0); // head node
  ListNode* p = head; // head node
  for (auto i : values) {
    p->next = new ListNode(i);
    p = p->next;
  }
  return head;
}

ListNode* BuildLinkListWithoutHeadnode(std::vector<int> values) {
  if (values.empty()) {
    return nullptr;
  }
  ListNode* head = new ListNode(values[0]); // head node
  ListNode* p = head; // head node
  for (auto i = 1; i < values.size(); i++) {
    p->next = new ListNode(values[i]);
    p = p->next;
  }
  return head;
}

ListNode* BuildCycleLinkList(std::vector<int> values, int cycle_index) {
  ListNode* head = new ListNode(0); // head node
  ListNode* p = head; // head node
  ListNode* cycle_node = nullptr; // head node
  for (auto i : values) {
    p->next = new ListNode(i);
    p = p->next;  // finally p is at tail
    if (i == cycle_index) {
      cycle_node = p;
    }
  }
  if (cycle_node) {
    p->next = cycle_node;
  }
  return head;
}

std::pair<ListNode*, ListNode*> BuildIntersectLinkList(std::vector<int> values1, int index1, std::vector<int> values2, int index2) {
  if (values1.size() <= index1 || values2.size() <= index2) {
    return std::make_pair(nullptr, nullptr);
  }
  if (values1[index1] != values2[index2]) {
    return std::make_pair(nullptr, nullptr);
  }
  ListNode* intersect; // intersect node
  ListNode* head1 = new ListNode(0); // head node
  ListNode* p = head1; // head node
  for (int i = 0; i < values1.size(); ++i) {
    if (i == index1) {
      intersect = p;
    }
    p->next = new ListNode(values1[i]);
    p = p->next;
  }

  ListNode* head2 = new ListNode(0); // head node
  p = head2; // head node
  for (int i = 0; i < values2.size(); ++i) {
    if (i + 1 == index2) {
      p->next = intersect;
      break;
    }
    p->next = new ListNode(values2[i]);
    p = p->next;
  }
  
  return std::make_pair(head1, head2);  // no template argument needed for make_pair
}

void PrintLinkList(ListNode* head) {
  if (!head) {
    cout << "empty list" << endl;
    return;
  }
  auto p = head;
  while(p) {
    std::cout << p->val << " ";
    p = p->next;
  }
  std::cout << std::endl;
}

void PrintCycleLinkList(ListNode* head) {
  auto p = head;
  std::set<ListNode*> nodes;
  while(p) {
    if (nodes.find(p) != nodes.end()) {
      // cycle point
      std::cout << p->val << " ";
      break;
    }
    nodes.insert(p);
    std::cout << p->val << " ";
    p = p->next;
  }
  std::cout << std::endl;
}

void PrintVector(const vector<int>& v) {
  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;
}