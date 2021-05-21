#include "../../test.h"
#include "../list.h"

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

bool verify(ListNode* head) {
  int count = 1;
  while (head != nullptr) {
    if (head->value != count) {
      return false;
    }

    ++count;
    head = head->next;
  }

  return true;
}

int main() {
  LinkedList input({});
  ASSERT_EQUALS(LinkedList(reverseList(input.getHead())).getLength(), 0);

  LinkedList input_for_recursion({});
  ASSERT_EQUALS(LinkedList(reverseListRecursively(input_for_recursion.getHead())).getLength(), 0);

  LinkedList input1({2,1});
  ASSERT_TRUE(verify(reverseList(input1.getHead())));

  LinkedList input_for_recursion1({2,1});
  ASSERT_TRUE(verify(reverseListRecursively(input_for_recursion1.getHead())));

  LinkedList input2({5,4,3,2,1});
  ASSERT_TRUE(verify(reverseList(input2.getHead())));

  LinkedList input_for_recursion2({5,4,3,2,1});
  ASSERT_TRUE(verify(reverseListRecursively(input_for_recursion2.getHead())));
}