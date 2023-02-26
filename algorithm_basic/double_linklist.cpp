/*
 * @Description: basic operation for double linklist
 * @Author: zhumingming
 * @Date: 2021-09-19 22:53:35
 * @LastEditors: zhumingming
 * @LastEditTime: 2021-09-19 23:25:36
 */
#include <iostream>
struct LinkNode
{
  LinkNode(int v):pre(nullptr),next(nullptr),value(v){}
  LinkNode * pre;
  LinkNode * next;
  int value;
};

struct DoubleLinkList
{
  LinkNode * head;
  LinkNode * tail;
  int size = 0;
  DoubleLinkList():head(nullptr),tail(nullptr){}

  void appendNode(int v){
    if(head == nullptr){
      head = new LinkNode(v);
      tail = head;
    }
    else {
      LinkNode * curr = head;
      while(curr ->next != nullptr){
        curr = curr->next;
      }
      LinkNode * tmp = new LinkNode(v);
      curr->next = tmp;
      tmp->pre = curr;
      tail = tmp;
    }
    ++size;
  }

  void printList(){
    LinkNode * curr = head;
    std::cout << "from head: ";
    while(curr!=nullptr){
      std::cout << curr->value << ", ";
      curr = curr->next;
    }
    std::cout << std::endl;
    curr = tail;
    std::cout << "from tail: ";
    while(curr!=nullptr){
      std::cout << curr->value << ", ";
      curr=curr->pre;
    }
    std::cout << std::endl;
  }

  void deleteNode(int index){
    if(index < 1 || index > size){
      std::cout << "invalid size!" << std::endl;
    }
    // find deleted node
    LinkNode * d_node = head;
    while(--index){
      d_node = d_node->next;
    }
    // delete node
    if(d_node == head){
      d_node->next->pre = nullptr;
      head = d_node->next;
    }
    else if(d_node == tail){
      d_node->pre->next = nullptr;
      tail = d_node->pre;
    }
    else {
      d_node->pre->next = d_node->next;
      d_node->next->pre = d_node->pre;
    }
    delete d_node;
  }
};

int main()
{
  DoubleLinkList dll;
  dll.appendNode(1);
  dll.appendNode(2);
  dll.appendNode(3);
  dll.appendNode(4);
  dll.printList();
  dll.deleteNode(4);
  dll.printList();
}