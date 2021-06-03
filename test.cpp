#include "test.h"
#include <iostream>
#include <vector>

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

void assertEquals(double actual, double expected, std::string file, int line) {
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

void assertEquals(std::vector<std::vector<int>> actual,
                  std::vector<std::vector<int>> expected,
                  std::string file,
                  int line) {
  if (actual != expected) {
    std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
              << " in " << file << std::endl;
  }
}
