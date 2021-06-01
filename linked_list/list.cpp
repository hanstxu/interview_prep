#include "list.h"
#include <initializer_list>
#include <iostream>

ListNode::ListNode() {
  this->value = 0;
  this->next = nullptr;
}

ListNode::ListNode(int value) {
  this->value = value;
  this->next = nullptr;
}

ListNode::ListNode(int value, ListNode* next) {
  this->value = value;
  this->next = next;
}

LinkedList::LinkedList() {
  this->head = nullptr;
  this->tail = nullptr;
}

LinkedList::LinkedList(ListNode* node) {
  this->head = node;
  this->tail = node;
}

LinkedList::LinkedList(int value) {
  this->head = new ListNode(value);
  this->tail = this->head;
}

LinkedList::LinkedList(std::initializer_list<int> values) {
  if (values.size() == 0) {
    this->head = nullptr;
    this->tail = nullptr;
    return;
  }

  std::initializer_list<int>::iterator it = values.begin();
  this->head = new ListNode(*it);
  this->tail = this->head;
  
  for (++it; it != values.end(); ++it) {
    addToList(*it);
  }
}

ListNode* LinkedList::getHead() {
  return this->head;
}

ListNode* LinkedList::getTail() {
  return this->tail;
}

ListNode* LinkedList::getNode(int index) {
  ListNode* curr = head;
  for (int i = 0; curr != nullptr && i < index; i++) {
    curr = curr->next;
  }
  return curr;
}

void LinkedList::addToList(ListNode* node) {
  if (this->head == nullptr) {
    this->head = node;
    this->tail = node;
    return;
  }
  
  ListNode* curr = tail;
  curr->next = node;
  tail = node;
}

void LinkedList::addToList(int value) {
  ListNode* node = new ListNode(value);
  addToList(node);
}

void LinkedList::addToList(std::initializer_list<int> values) {
  for (auto value : values) {
    addToList(value);
  }
}

int LinkedList::getLength() {
  int length = 0;
  ListNode* curr = head;
  while (curr != nullptr) {
    length++;
    curr = curr->next;
  }
  return length;
}

void LinkedList::print() {
  if (this->head == nullptr) {
    std::cout << "Empty linked list" << std::endl;
    return;
  }

  std::cout << "Linked List:";
  ListNode* curr = head;
  while (curr != nullptr) {
    std::cout << " " << curr->value;
    curr = curr->next;
  }
  std::cout << std::endl;
}
