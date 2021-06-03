#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>

void assertTrue(bool value, std::string file, int line);
void assertFalse(bool value, std::string file, int line);
void assertEquals(int actual, int expected, std::string file, int line);
void assertEquals(double actual, double expected, std::string file, int line);
void assertEquals(std::string actual, std::string expected, std::string, int line);
void assertEquals(std::vector<int> actual, std::vector<int> expected, std::string, int line);
void assertEquals(std::vector<std::vector<int>> actual,
                  std::vector<std::vector<int>> expected,
                  std::string file,
                  int line);

#define ASSERT_TRUE(value) assertTrue(value, __FILE__, __LINE__)
#define ASSERT_FALSE(value) assertFalse(value, __FILE__, __LINE__)
#define ASSERT_EQUALS(actual, expected) assertEquals(actual, expected, __FILE__, __LINE__)

#endif
