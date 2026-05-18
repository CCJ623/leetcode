#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    if (numCourses == 0 || prerequisites.empty() ||
        prerequisites.front().empty()) {
      return true;
    }

    vector<size_t> in_degrees(numCourses, 0);
    unordered_map<int, vector<int>> post_courses;
    for (const auto &pre : prerequisites) {
      ++in_degrees[pre.front()];
      post_courses[pre[1]].push_back(pre.front());
    }

    queue<int> courses;
    for (size_t i = 0; i < in_degrees.size(); ++i) {
      if (in_degrees[i] == 0) {
        courses.push(i);
      }
    }

    while (!courses.empty()) {
      auto course = courses.front();
      courses.pop();
      --numCourses;

      for (const auto &next_course : post_courses[course]) {
        --in_degrees[next_course];
        if (in_degrees[next_course] == 0) {
          courses.push(next_course);
        }
      }
    }

    return numCourses == 0;
  }
};