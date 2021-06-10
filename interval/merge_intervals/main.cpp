#include "../../test.h"
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Given an array of intervals, merge all overlapping
 * intervals.
 */
bool sortIntervals(vector<int>& a, vector<int>& b) {
  return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
  if (intervals.empty()) {
    return intervals;
  }

  sort(intervals.begin(), intervals.end(), sortIntervals);

  vector<vector<int>> result = { intervals[0] };
  for (int i = 1; i < intervals.size(); ++i) {
    if (result.back()[1] < intervals[i][0]) {
      result.push_back(intervals[i]);

    } else {
      result.back()[1] = max(result.back()[1], intervals[i][1]);
    }
  }

  return result;
}

int main() {
  vector<vector<int>> empty_intervals = {};
  ASSERT_EQUALS(merge(empty_intervals), {});

  vector<vector<int>> intervals_1 = {{8,11},{4,6},{1,3},{2,5}};
  ASSERT_EQUALS(merge(intervals_1), (vector<vector<int>>{{1,6}, {8,11}}));

  vector<vector<int>> intervals_2 = {{1,3},{2,6},{8,10},{15,18}};
  ASSERT_EQUALS(merge(intervals_2), (vector<vector<int>>{{1,6},{8,10},{15,18}}));

  vector<vector<int>> intervals_3 = {{1,4},{4,5}};
  ASSERT_EQUALS(merge(intervals_3), (vector<vector<int>>{{1,5}}));

  vector<vector<int>> intervals_4 = {{1,21},{3,6},{3,7},{19,20}};
  ASSERT_EQUALS(merge(intervals_4), (vector<vector<int>>{{1,21}}));
}
