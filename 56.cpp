#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.empty() || intervals.front().empty()) {
      return {};
    }

    ranges::sort(intervals, [](const auto &lhs, const auto &rhs) {
      return lhs[0] < rhs[0];
    });

    vector<vector<int>> result;
    auto left = intervals.front()[0];
    auto right = intervals.front()[1];
    for (const auto &interval : intervals) {
      auto interval_left = interval[0];
      auto interval_right = interval[1];
      if (interval_left <= right) {
        right = max(right, interval_right);
      } else {
        result.push_back({left, right});
        left = interval_left;
        right = interval_right;
      }
    }
    result.push_back({left, right});

    return result;
  }
};