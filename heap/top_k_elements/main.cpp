#include "../../test.h"
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

/**
 * Given an array of numbers, return the k most frequent elements.
 */

// a.first = number
// a.second = frequency
struct CompareFrequency {
  bool operator() (const pair<int, int> a, const pair<int, int> b) {
    return a.second <= b.second;
  }
};

vector<int> topKFrequent(vector<int>& numbers, int k) {
  unordered_map<int, int> number_count;
  for (auto number: numbers) {
    if (number_count.find(number) == number_count.end()) {
      number_count[number] = 1;

    } else {
      number_count[number]++;
    }
  }

  priority_queue<pair<int, int>,
                 vector<pair<int, int>>,
                 CompareFrequency>
    most_frequent_heap;

  for (const auto& it: number_count) {
    pair<int, int> frequency_pair = {it.first, it.second};
    most_frequent_heap.push(frequency_pair);
  }

  vector<int> result;
  for (int i = 0; i < k; ++i) {
    int number = most_frequent_heap.top().first;
    result.push_back(number);
    most_frequent_heap.pop();
  }

  return result;
}

vector<int> topKFrequentCountingSort(vector<int>& numbers, int k) {
  unordered_map<int, int> buckets;
  for (auto number: numbers) {
    buckets[number]++;
  }

  vector<pair<int, int>> frequency_array(buckets.begin(), buckets.end());

  sort(frequency_array.begin(), frequency_array.end(), [](pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) {
      return p1.first < p2.first;
    }

    return p1.second > p2.second;
  });

  vector<int> result;
  for (int i = 0; i < k; ++i) {
    result.push_back(frequency_array[i].first);
  }
  return result;
}

int main() {
  vector<int> input1 = {1};
  vector<int> input2 = {1,1,1,2,2,3};
  vector<int> input3 = {1,2};

  ASSERT_EQUALS(topKFrequent(input1, 1), (vector<int>{1}));
  ASSERT_EQUALS(topKFrequent(input2, 2), (vector<int>{1,2}));
  ASSERT_EQUALS(topKFrequent(input2, 3), (vector<int>{1,2,3}));
  ASSERT_EQUALS(topKFrequent(input3, 2), (vector<int>{1,2}));

  ASSERT_EQUALS(topKFrequentCountingSort(input1, 1), (vector<int>{1}));
  ASSERT_EQUALS(topKFrequentCountingSort(input2, 2), (vector<int>{1,2}));
  ASSERT_EQUALS(topKFrequentCountingSort(input2, 3), (vector<int>{1,2,3}));
  ASSERT_EQUALS(topKFrequentCountingSort(input3, 2), (vector<int>{1,2}));
}
