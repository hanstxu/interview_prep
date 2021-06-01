#include "test.h"
#include <iostream>
#include <vector>
#include "linked_list/list.h"

void assertTrue(bool value, std::string file, int line) {
  if (!value) {
	std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
            << " in " << file << std::endl;
  }
}

void assertFalse(bool value, std::string file, int line) {
  if (value) {
	std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
            << " in " << file << std::endl;
  }
}

void assertEquals(int actual, int expected, std::string file, int line) {
	if (actual != expected) {
    std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
              << " in " << file << std::endl;
  }
}

void assertEquals(std::string actual, std::string expected, std::string file, int line) {
	if (actual != expected) {
    std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
              << " in " << file << std::endl;
  }
}

void assertEquals(std::vector<int> actual, std::vector<int> expected, std::string file, int line) {
	if (actual != expected) {
    std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
              << " in " << file << std::endl;
  }
}

void assertEquals(ListNode* actual, ListNode* expected, std::string file, int line) {
  while (actual != nullptr && expected != nullptr) {
    if (actual->value != expected->value) {
      std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
              << " in " << file << std::endl;
      return;
    }

    actual = actual->next;
    expected = expected->next;
  }

  if (actual != nullptr) {
    std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
              << " in " << file << std::endl;

  } else if (expected != nullptr) {
    std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
              << " in " << file << std::endl;
  }
}

void assertEquals(LinkedList actual, LinkedList expected, std::string file, int line) {
  assertEquals(actual.getHead(), expected.getHead(), file, line);
}
