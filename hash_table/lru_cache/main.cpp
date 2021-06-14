#include "../../test.h"

#include <utility>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
  }

  int read(int key) {
    auto it = cache.find(key);
    if (it == cache.end()) {
      return -1;
    }

    touch(it);
    return it->second.first;
  }

  void write(int key, int value) {
    auto it = cache.find(key);
    if (it == cache.end()) {
      if (cache.size() == capacity) {
        cache.erase(use_list.back());
        use_list.pop_back();
      }

      use_list.push_front(key);

    } else {
      touch(it);
    }

    cache[key] = { value, use_list.begin() };
  }

private:
  int capacity;

  typedef list<int> Linked_List;
  typedef pair<int, Linked_List::iterator> Item;
  typedef unordered_map<int, Item> Hash_Table;

  void touch(Hash_Table::iterator it) {
    int key = it->first;
    use_list.erase(it->second.second);
    use_list.push_front(key);
    it->second.second = use_list.begin();
  }

  Linked_List use_list;
  Hash_Table cache;
};

int main() {
  LRUCache lruCache = LRUCache(2);
  lruCache.write(1, 1);
  lruCache.write(2, 2);
  ASSERT_EQUALS(lruCache.read(1), 1);

  lruCache.write(3, 3);
  ASSERT_EQUALS(lruCache.read(2), -1);

  lruCache.write(4,4);
  ASSERT_EQUALS(lruCache.read(1), -1);
  ASSERT_EQUALS(lruCache.read(3), 3);
  ASSERT_EQUALS(lruCache.read(4), 4);
}
