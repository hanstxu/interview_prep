#include "../../test.h"
#include "../list.h"

/**
 * Given a singly linked list, return that linked list reversed.
 */
ListNode* reverseList(ListNode* head) {
  if (head == nullptr) {
    return nullptr;
  }

  ListNode* prev = nullptr;
  ListNode* next = head->next;
  while (next != nullptr) {
    head->next = prev;
    prev = head;
    head = next;
    next = head->next;
  }

  head->next = prev;
  return head;
}

ListNode* reverseListRecursivelyHelper(ListNode* head, ListNode* prev);

ListNode* reverseListRecursively(ListNode* head) {
  if (head == nullptr) {
    return nullptr;
  }

  return reverseListRecursivelyHelper(head, nullptr);
}

ListNode* reverseListRecursivelyHelper(ListNode* head, ListNode* prev) {
  if (head->next == nullptr) {
    head->next = prev;
    return head;
  }

  ListNode* next = head->next;
  head->next = prev;
  return reverseListRecursivelyHelper(next, head);
}

int main() {
  LinkedList input({});
  ASSERT_EQUALS(reverseList(input.getHead()), input.getHead());

  LinkedList input_for_recursion({});
  ASSERT_EQUALS(reverseListRecursively(input_for_recursion.getHead()), input_for_recursion.getHead());

  LinkedList input1({2,1});
  ASSERT_EQUALS(reverseList(input1.getHead()), (LinkedList{1,2}).getHead());

  LinkedList input_for_recursion1({2,1});
  ASSERT_EQUALS(reverseList(input_for_recursion1.getHead()), (LinkedList{1,2}).getHead());

  LinkedList input2({5,4,3,2,1});
  ASSERT_EQUALS(reverseList(input2.getHead()), (LinkedList{1,2,3,4,5}).getHead());

  LinkedList input_for_recursion2({5,4,3,2,1});
  ASSERT_EQUALS(reverseList(input_for_recursion2.getHead()), (LinkedList{1,2,3,4,5}).getHead());
}