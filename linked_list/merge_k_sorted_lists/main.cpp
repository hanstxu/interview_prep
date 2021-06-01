#include "../../test.h"
#include "../list.h"
#include <vector>
#include <queue> // priority_queue
#include <utility> // pair
using namespace std;

/**
 * Given an array of k sorted linked lists, merge all the linked
 * lists into 1 sorted linked list and return that final list.
 */

// a.first = value at top of linked list
// b.second = index of linked list in array
struct ComparatorForMinHeap {
  bool operator()(const pair<int, int> a, const pair<int, int> b) {
    return a.first > b.first;
  }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
  priority_queue<pair<int, int>,
                 vector<pair<int, int>>,
                 ComparatorForMinHeap>
    min_heap;

  for (int i = 0; i < lists.size(); ++i) {
    if (lists[i] == nullptr) {
      continue;
    }

    pair<int, int> value_to_list_index = {lists[i]->value, i};
    min_heap.push(value_to_list_index);
    lists[i] = lists[i]->next;
  }

  ListNode* dummy_node = new ListNode();
  ListNode* curr = dummy_node;

  while (!min_heap.empty()) {
    int value = min_heap.top().first;
    curr->next = new ListNode(value);
    curr = curr->next;

    int list_index = min_heap.top().second;
    min_heap.pop();

    ListNode* list = lists[list_index];
    if (list != nullptr) {
      pair<int, int> value_to_list_index = {list->value, list_index};
      min_heap.push(value_to_list_index);
      lists[list_index] = list->next;
    }
  }

  return dummy_node->next;
}

int main() {
  LinkedList empty_list;
  LinkedList list1{1,4,5};
  LinkedList list2{1,3,4};
  LinkedList list3{2,6};
  LinkedList list4{1,3,7,11};
  LinkedList list5{6,8,9};

  vector<ListNode*> empty_input;
  vector<ListNode*> input1{list1.getHead(), list2.getHead(), list3.getHead()};
  vector<ListNode*> input2{list1.getHead(), list2.getHead(), list3.getHead(), list4.getHead(), list5.getHead()};

  ASSERT_EQUALS(mergeKLists(empty_input), empty_list.getHead());
  ASSERT_EQUALS(mergeKLists(input1), (LinkedList{1,1,2,3,4,4,5,6}).getHead());
  ASSERT_EQUALS(mergeKLists(input2), (LinkedList{1,1,1,2,3,3,4,4,5,6,6,7,8,9,11}).getHead());
}
