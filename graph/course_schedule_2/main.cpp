#include "../../test.h"

#include <vector>
#include <queue>
using namespace std;

/**
 * Given a list of courses and their prerequisites, return a possible
 * ordering of courses to take that will ensure that all courses will
 * be taken.
 */
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
  vector<vector<int>> adjacency_list(numCourses, vector<int>());
  vector<int> degrees(numCourses, 0);

  for (auto prerequisite: prerequisites) {
    int required_course = prerequisite[1];
    int dependent_course = prerequisite[0];

    adjacency_list[required_course].push_back(dependent_course);
    degrees[dependent_course]++;
  }

  queue<int> available_courses;
  for (int i = 0; i < degrees.size(); ++i) {
    if (degrees[i] == 0) {
      available_courses.push(i);
    }
  }

  vector<int> result;
  while (!available_courses.empty()) {
    int course = available_courses.front();
    available_courses.pop();
    result.push_back(course);

    for (int dependent_course: adjacency_list[course]) {
      degrees[dependent_course]--;
      if (degrees[dependent_course] == 0) {
        available_courses.push(dependent_course);
      }
    }
  }

  if (result.size() != numCourses) {
    return vector<int>();
  }

  return result;
}

int main() {
  vector<vector<int>> no_prerequisites;
  ASSERT_EQUALS(findOrder(1, no_prerequisites), vector<int>{0});

  vector<vector<int>> prerequisites_1 = {{1,0}};
  ASSERT_EQUALS(findOrder(2, prerequisites_1), (vector<int>{0,1}));

  vector<vector<int>> prerequisites_2 = {{1,0},{2,0},{3,1},{3,2}};
  ASSERT_EQUALS(findOrder(4, prerequisites_2), (vector<int>{0,1,2,3}));

  vector<vector<int>> prerequisites_3 = {{11,5},{11,7},{8,7},{8,3},{10,3},
                                         {2,11},{9,11},{10,11},{9,8}};
  ASSERT_EQUALS(findOrder(12, prerequisites_3), (vector<int>{0,1,3,4,5,6,7,11,8,2,10,9}));

  vector<vector<int>> circular_prerequisites = {{1,0},{2,1},{0,2}};
  ASSERT_EQUALS(findOrder(3, circular_prerequisites), vector<int>());
  ASSERT_EQUALS(findOrder(6, circular_prerequisites), vector<int>());
}
