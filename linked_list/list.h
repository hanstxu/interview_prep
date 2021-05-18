#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <initializer_list>

class ListNode {
  public:
    ListNode();
    ListNode(int value);
    ListNode(int value, ListNode* next);
    int value;
    ListNode* next;
};

class LinkedList {
  public:
    LinkedList();

    LinkedList(ListNode* head);

    LinkedList(int value);

    LinkedList(std::initializer_list<int> values);

    ListNode* getHead();

    ListNode* getTail();

    ListNode* getNode(int index);

    void addToList(ListNode* node);

    void addToList(int value);

    void addToList(std::initializer_list<int> values);

    int getLength();

    void print();
  private:
    ListNode* head;
    ListNode* tail;
};

#endif
