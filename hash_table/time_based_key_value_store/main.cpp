#include "../../test.h"
#include <unordered_map>
#include <map>
using namespace std;

/**
 * Create a timebased key-value data store class that supports two operations
 *    1. set(key, value, timestamp)
 *    2. get(key, timestamp) returns the largest value where timestamp_prev
         <= timestamp or no value
 */

class TimeMap {
public:
  TimeMap() { }

  void set(string key, string value, int timestamp) {
      data_store[key][timestamp] = value;
  }

  string get(string key, int timestamp) {
    if (data_store.find(key) == data_store.end()) {
      return "";
    }

    Bst_Pair& timestamp_values = data_store[key];
    auto it = timestamp_values.upper_bound(timestamp);
    if (it == timestamp_values.begin()) {
      return "";
    }

    --it;
    return it->second;
  }

private:
  typedef map<int, string> Bst_Pair;
  unordered_map<string, Bst_Pair> data_store;
};


int main() {
  TimeMap time_map_1 = TimeMap();
  time_map_1.set("foo", "bar", 1);

  ASSERT_EQUALS(time_map_1.get("foo", 1), "bar");
  ASSERT_EQUALS(time_map_1.get("foo", 3), "bar");

  time_map_1.set("foo", "bar2", 4);
  ASSERT_EQUALS(time_map_1.get("foo", 4), "bar2");
  ASSERT_EQUALS(time_map_1.get("foo", 5), "bar2");

  TimeMap time_map_2 = TimeMap();
  time_map_2.set("love", "high", 10);
  time_map_2.set("love", "low", 20);

  ASSERT_EQUALS(time_map_2.get("love", 5), "");
  ASSERT_EQUALS(time_map_2.get("love", 10), "high");
  ASSERT_EQUALS(time_map_2.get("love", 15), "high");
  ASSERT_EQUALS(time_map_2.get("love", 20), "low");
  ASSERT_EQUALS(time_map_2.get("love", 25), "low");
}
