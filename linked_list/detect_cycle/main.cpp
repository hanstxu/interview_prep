#include "../../test.h"
#include "../list.h"
using namespace std;

/**
 * Given a singly-linked list, determine if the
 * linked list has a cycle.
 */
bool hasCycle(ListNode* head) {
  if (head == nullptr) {
    return false;
  }

  ListNode* slow = head;
  ListNode* fast = head->next;

  while (fast != nullptr) {
    if (fast == slow) {
      return true;
    }

    if (fast->next == nullptr) {
      return false;
    }

    fast = fast->next->next;
    slow = slow->next;
  }

  return false;
}

int main() {
  LinkedList input({});
  ASSERT_FALSE(hasCycle(input.getHead()));

  LinkedList input1({1});
  ASSERT_FALSE(hasCycle(input1.getHead()));

  LinkedList input2({1,2});
  ASSERT_FALSE(hasCycle(input2.getHead()));

  LinkedList input3({1,2,3});
  ASSERT_FALSE(hasCycle(input3.getHead()));

  LinkedList input4({1});
  input4.getTail()->next = input4.getHead();
  ASSERT_TRUE(hasCycle(input4.getHead()));

  LinkedList input5({1,2});
  input5.getTail()->next = input5.getHead();
  ASSERT_TRUE(hasCycle(input5.getHead()));

  LinkedList input6({1,2,3});
  input6.getTail()->next = input6.getHead();
  ASSERT_TRUE(hasCycle(input6.getHead()));
}
