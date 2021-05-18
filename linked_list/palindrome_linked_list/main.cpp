#include "../../test.h"
#include "../list.h"
#include <iostream>
using namespace std;

ListNode* reverseList(ListNode* head, ListNode* tail, int length) {
  ListNode* prev = tail;
  ListNode* curr = head;
  for (int i = length; i > 0; --i) {
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

/**
 * Given the head of a linked list, determine if it's a palindrome.
 */
bool isPalindrome(ListNode* head) {
  LinkedList list = LinkedList(head);
  int length = list.getLength();

  int halfListLength = length / 2;
  int midpoint = length / 2;
  int startOfSecondHalf = (length + 1) / 2;

  ListNode* midPointNode = list.getNode(midpoint);

  ListNode* secondHalfHead = list.getNode(startOfSecondHalf);
  ListNode* firstHalfHead = reverseList(head, nullptr, halfListLength);

  bool result = true;
  ListNode* firstCurr = firstHalfHead;
  ListNode* secondCurr = secondHalfHead;
  for (int i = 0; i < halfListLength; i++) {
    if (firstCurr->value != secondCurr->value) {
      result = false;
      break;
    }

    firstCurr = firstCurr->next;
    secondCurr = secondCurr->next;
  }

  // restore original list
  reverseList(firstHalfHead, midPointNode, halfListLength);
  return result;
}

int main() {
  ASSERT_TRUE(isPalindrome(LinkedList({}).getHead()));
  ASSERT_TRUE(isPalindrome(LinkedList({1}).getHead()));
  ASSERT_TRUE(isPalindrome(LinkedList({1, 1}).getHead()));
  ASSERT_TRUE(isPalindrome(LinkedList({1, 2, 1}).getHead()));
  ASSERT_TRUE(isPalindrome(LinkedList({1, 2, 2, 1}).getHead()));
  ASSERT_TRUE(isPalindrome(LinkedList({1, 2, 3, 2, 1}).getHead()));

  ASSERT_FALSE(isPalindrome(LinkedList({1, 2}).getHead()));
  ASSERT_FALSE(isPalindrome(LinkedList({1, 2, 3}).getHead()));
  ASSERT_FALSE(isPalindrome(LinkedList({1, 2, 3, 1}).getHead()));
  ASSERT_FALSE(isPalindrome(LinkedList({1, 2, 3, 2, 3}).getHead()));
}