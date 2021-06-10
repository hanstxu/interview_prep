#include "../../test.h"
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Given a sorted list of non-overlapping intervals, insert a
 * new interval into that list and merge if necessary.
 */
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& new_interval) {
  vector<vector<int>> result;
  int new_start_time = new_interval[0];
  int new_end_time = new_interval[1];

  int i = 0;
  while (i < intervals.size() && intervals[i][1] < new_start_time) {
    result.push_back(intervals[i]);
    ++i;
  }

  while (i < intervals.size() && intervals[i][0] <= new_end_time) {
    new_start_time = min(new_start_time, intervals[i][0]);
    new_end_time = max(new_end_time, intervals[i][1]);
    ++i;
  }
  result.push_back(vector<int>{new_start_time, new_end_time});

  while (i < intervals.size()) {
    result.push_back(intervals[i]);
    ++i;
  }

  return result;
}

int main() {
  vector<vector<int>> empty_intervals{};
  vector<int> new_interval{1,3};
  ASSERT_EQUALS(insert(empty_intervals, new_interval),
                (vector<vector<int>>{{1,3}}));

  vector<vector<int>> intervals_1 = {{4,6},{8,10}};
  vector<int> new_interval_1 = {1,3};
  ASSERT_EQUALS(insert(intervals_1, new_interval_1),
                (vector<vector<int>>{{1,3},{4,6},{8,10}}));

  vector<vector<int>> intervals_2 = {{4,6},{8,10}};
  vector<int> new_interval_2 = {4,7};
  ASSERT_EQUALS(insert(intervals_2, new_interval_2),
                (vector<vector<int>>{{4,7},{8,10}}));

  vector<vector<int>> intervals_3 = {{4,6},{8,10}};
  vector<int> new_interval_3 = {4,9};
  ASSERT_EQUALS(insert(intervals_3, new_interval_3),
                (vector<vector<int>>{{4,10}}));

  vector<vector<int>> intervals_4 = {{4,6},{8,10}};
  vector<int> new_interval_4 = {4,13};
  ASSERT_EQUALS(insert(intervals_4, new_interval_4),
                (vector<vector<int>>{{4,13}}));
}
