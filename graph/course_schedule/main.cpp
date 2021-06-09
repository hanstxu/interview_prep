#include "../../test.h"
#include <vector>
#include <queue>
using namespace std;

/**
 * Given a number of courses, a list of prerequisites for
 * each course, determine whether it's possible to take
 * all courses given the prerequisite list.
 */
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  vector<vector<int>> adjacency_list(numCourses, vector<int>());
  vector<int> degrees(numCourses, 0);

  for (auto prerequisite: prerequisites) {
    int required_course = prerequisite[1];
    int dependent_course = prerequisite[0];

    adjacency_list[required_course].push_back(dependent_course);
    degrees[dependent_course]++;
  }

  queue<int> taken_courses;
  for (int i = 0; i < degrees.size(); ++i) {
    if (degrees[i] == 0) {
      taken_courses.push(i);
    }
  }

  int n = 0;
  while (!taken_courses.empty()) {
    int taken_course = taken_courses.front();
    taken_courses.pop();

    n++;

    vector<int> dependent_courses = adjacency_list[taken_course];
    for (auto dependent_course: dependent_courses) {
      if (--degrees[dependent_course] == 0) {
        taken_courses.push(dependent_course);
      }
    }
  }

  return n == numCourses;
}

int main() {
  vector<vector<int>> no_prerequisites;
  ASSERT_TRUE(canFinish(0, no_prerequisites));
  ASSERT_TRUE(canFinish(4, no_prerequisites));

  vector<vector<int>> single_prerequisite{{1,0}};
  ASSERT_TRUE(canFinish(2, single_prerequisite));

  vector<vector<int>> loop_prerequisite{{1,0}, {0,1}};
  ASSERT_FALSE(canFinish(2, loop_prerequisite));

  vector<vector<int>> wikipedia_prerequisites{
    {11,5},{11,7},{8,7},{8,3},{10,3},
    {2,11},{9,11},{3,11},{9,8}};
  ASSERT_TRUE(canFinish(12, wikipedia_prerequisites));
}
