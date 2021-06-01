#include "../../test.h"
#include "../list.h"
using namespace std;

/**
 * Given a linked list, remove the nth node from the
 * end of the list.
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
  if (head == nullptr) {
    return nullptr;
  }

  ListNode* dummy = new ListNode(0, head);

  ListNode* prev = dummy;
  ListNode* slow = head;
  ListNode* fast = head;

  while (n > 0) {
    fast = fast->next;
    --n;
  }

  while (fast != nullptr) {
    prev = prev->next;
    slow = slow->next;
    fast = fast->next;
  }

  prev->next = slow->next;
  return dummy->next;
}

int main() {
  LinkedList empty_list;
  LinkedList input1{1};
  LinkedList input2{1,2};
  LinkedList input3{1,2};
  LinkedList input4{1,2,3,4,5};

  ASSERT_EQUALS(removeNthFromEnd(empty_list.getHead(), 0), empty_list.getHead());
  ASSERT_EQUALS(removeNthFromEnd(input1.getHead(), 1), empty_list.getHead());
  ASSERT_EQUALS(removeNthFromEnd(input2.getHead(), 1), (LinkedList{1}).getHead());
  ASSERT_EQUALS(removeNthFromEnd(input3.getHead(), 2), (LinkedList{2}).getHead());
  ASSERT_EQUALS(removeNthFromEnd(input4.getHead(), 2), (LinkedList{1,2,3,5}).getHead());
}
