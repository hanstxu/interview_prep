#include "../../test.h"
#include "../list.h"
using namespace std;

/**
 * Given two sorted linked lists, return a sorted linked list
 * that merges the two lists.
 */
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
  if (head1 == nullptr) {
    return head2;
  }

  if (head2 == nullptr) {
    return head1;
  }

  ListNode* dummy = new ListNode(0);
  ListNode* curr = dummy;

  while (head1 != nullptr && head2 != nullptr) {
    if (head1->value < head2->value) {
      curr->next = new ListNode(head1->value);
      head1 = head1->next;

    } else {
      curr->next = new ListNode(head2->value);
      head2 = head2->next;
    }

    curr = curr->next;
  }

  if (head1 == nullptr) {
    curr->next = head2;
  } else {
    curr->next = head1;
  }

  return dummy->next;
}

int main() {
  LinkedList list1({});
  LinkedList list2({1,3,5});
  LinkedList list3({2,3,6});
  LinkedList lists_2_3({1,2,3,3,5,6});
  LinkedList list4({1,2,4});
  LinkedList list5({1,3,4});
  LinkedList lists_4_5({1,1,2,3,4,4});

  ListNode* result0 = mergeTwoLists(list1.getHead(), list1.getHead());
  ASSERT_EQUALS(result0, list1.getHead());

  ListNode* result1 = mergeTwoLists(list1.getHead(), list2.getHead());
  ASSERT_EQUALS(result1, list2.getHead());

  ListNode* result2 = mergeTwoLists(list2.getHead(), list1.getHead());
  ASSERT_EQUALS(result2, list2.getHead());

  ListNode* result3 = mergeTwoLists(list2.getHead(), list3.getHead());
  ASSERT_EQUALS(result3, lists_2_3.getHead());

  ListNode* result4 = mergeTwoLists(list3.getHead(), list2.getHead());
  ASSERT_EQUALS(result4, lists_2_3.getHead());

  ListNode* result5 = mergeTwoLists(list4.getHead(), list5.getHead());
  ASSERT_EQUALS(result5, lists_4_5.getHead());

  ListNode* result6 = mergeTwoLists(list5.getHead(), list4.getHead());
  ASSERT_EQUALS(result6, lists_4_5.getHead());
}