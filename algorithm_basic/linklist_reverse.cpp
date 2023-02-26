/*
 * @Description: reverse a single linklist
 * @Author: zhumingming
 * @Date: 2021-09-19 22:11:49
 * @LastEditors: zhumingming
 * @LastEditTime: 2021-09-19 22:52:04
 */

#include <iostream>

class LinkNode {
public:
  LinkNode(int v):value(v),next(nullptr)
  {}
  LinkNode * next;
  int value;  // todo: change to template
};

class LinkList {
public:
  LinkList(){
    head = nullptr;
  }
  ~LinkList(){
    while (head != nullptr)
    {
      LinkNode * curr = head;
      head= head->next;
      delete curr;
    }
    std::cout << "finish destruct linklist" << std::endl;
  }
  void appendNode(int value){
    if(head == nullptr){
      head = new LinkNode(value);
      return;
    }
    else {
      LinkNode * curr = head;
      while(curr->next != nullptr){
        curr=curr->next;
      }
      // curr is final node now
      LinkNode * tmp = new LinkNode(value);
      curr->next = tmp;
    }
    std::cout << "add node: " << value << std::endl;
  }

  void reverseLinklist(){
    LinkNode * pre = nullptr;
    LinkNode * curr = head;
    while (curr != nullptr)
    {
      LinkNode * next = curr->next;
      curr->next = pre;
      pre = curr;
      curr = next;
    }
    head = pre;
  }

  void printList(){
    LinkNode * curr = head;
    std::cout << "linklist value: ";
    while (curr != nullptr)
    {
      std::cout << " " << curr->value << ",";
      curr= curr->next;
    }
    std::cout << std::endl;
  }

  LinkNode * head;
  int size = 0;
};

int main()
{
  LinkList ll;
  ll.appendNode(1);
  ll.appendNode(2);
  ll.appendNode(3);
  ll.appendNode(4);
  ll.printList();
  ll.reverseLinklist();
  ll.printList();

  return 0;
}