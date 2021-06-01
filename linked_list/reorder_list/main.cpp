#include "../../test.h"
#include "../list.h"
using namespace std;

/**
 * Given a linked list, reorder the list so that it contains
 * both the first half of the list and a reversed second
 * half of the of the list intermixed.
 */
ListNode* reverseList(ListNode* curr) {
  if (curr == nullptr) {
    return curr;
  }

  ListNode* prev = nullptr;
  ListNode* next = curr->next;
  while (next != nullptr) {
    curr->next = prev;
    prev = curr;
    curr = next;
    next = next->next;
  }

  curr->next = prev;
  return curr;
}

void reorderList(ListNode* head) {
  if (head == nullptr) {
    return;
  }

  ListNode* slow = head;
  ListNode* fast = head;
  while (fast != nullptr) {
    slow = slow->next;
    fast = fast->next;

    if (fast != nullptr) {
      fast = fast->next;
    }
  }

  ListNode* front_curr = head;
  ListNode* back_curr = reverseList(slow);
  ListNode* front_next = front_curr->next;
  while (back_curr != nullptr) {
    front_curr->next = back_curr;
    back_curr = back_curr->next;

    front_curr->next->next = front_next;
    front_curr = front_next;
    front_next = front_next->next;
  }

  front_curr->next = nullptr;
}


int main() {
  LinkedList empty_list;
  LinkedList input0{1};
  LinkedList input1{1,2,3,4};
  LinkedList input2{1,2,3,4,5};

  reorderList(empty_list.getHead());
  ASSERT_EQUALS(empty_list, empty_list);

  reorderList(input0.getHead());
  ASSERT_EQUALS(input0, input0);

  reorderList(input1.getHead());
  ASSERT_EQUALS(input1, (LinkedList{1,4,2,3}));

  reorderList(input2.getHead());
  ASSERT_EQUALS(input2, (LinkedList{1,5,2,4,3}));
}
