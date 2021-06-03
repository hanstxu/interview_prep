#include "../../test.h"
#include <vector>
#include <queue>
using namespace std;

/**
 * Given a data stream of numbers, return the median
 * from that data stream.
 */
struct ComparatorForMinHeap {
  bool operator() (int new_value, int top) {
    return new_value >= top;
  }
};

struct ComparatorForMaxHeap {
  bool operator() (int new_value, int top) {
    return new_value <= top;
  }
};

class MedianFinder {
public:
  MedianFinder() {
    even = true;
  }

  void addNum(int num) {
    even = !even;
    if (even) {
      max_heap.push(num);
      min_heap.push(max_heap.top());
      max_heap.pop();

    } else {
      if (max_heap.empty()) {
        max_heap.push(num);

      } else {
        min_heap.push(num);
        max_heap.push(min_heap.top());
        min_heap.pop();
      }
    }
  }

  double findMedian() {
    if (even) {
      return (min_heap.top() + max_heap.top()) / 2.0;

    } else {
      return max_heap.top();
    }
  }
private:
  priority_queue<int, vector<int>, ComparatorForMinHeap> min_heap;
  priority_queue<int, vector<int>, ComparatorForMaxHeap> max_heap;
  bool even;
};

int main() {
  MedianFinder median_finder = MedianFinder();
  median_finder.addNum(1);
  median_finder.addNum(2);
  ASSERT_EQUALS(median_finder.findMedian(), 1.5);

  median_finder.addNum(3);
  ASSERT_EQUALS(median_finder.findMedian(), 2.0);
}
