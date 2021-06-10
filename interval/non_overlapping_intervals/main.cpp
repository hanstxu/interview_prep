#include "../../test.h"
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Given an array of intervals, return the minumum number
 * of intervals that need to be removed to make the rest
 * of the intervals non-overlapping.
 */
bool sortByEndTime(vector<int>& a, vector<int>& b) {
  return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
  if (intervals.empty()) {
    return 0;
  }

  sort(intervals.begin(), intervals.end(), sortByEndTime);
  int end_time = intervals[0][1];
  int removed_count = 0;

  for (int i = 1; i < intervals.size(); ++i) {
    if (end_time <= intervals[i][0]) {
      end_time = intervals[i][1];

    } else {
      removed_count++;
    }
  }

  return removed_count;
}

int main() {
  vector<vector<int>> empty_intervals;
  ASSERT_EQUALS(eraseOverlapIntervals(empty_intervals), 0);

  vector<vector<int>> intervals_1 = {{1,4},{3,5},{2,6},{7,9}};
  ASSERT_EQUALS(eraseOverlapIntervals(intervals_1), 2);

  vector<vector<int>> intervals_2 = {{1,4},{4,5},{2,6},{7,9}};
  ASSERT_EQUALS(eraseOverlapIntervals(intervals_2), 1);

  vector<vector<int>> intervals_3 = {{1,2},{2,3},{3,4},{1,3}};
  ASSERT_EQUALS(eraseOverlapIntervals(intervals_3), 1);

  vector<vector<int>> intervals_4 = {{1,2},{1,2},{1,2}};
  ASSERT_EQUALS(eraseOverlapIntervals(intervals_4), 2);

  vector<vector<int>> intervals_5 = {{1,2},{2,3}};
  ASSERT_EQUALS(eraseOverlapIntervals(intervals_5), 0);
}
