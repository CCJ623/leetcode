#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.empty() || intervals.front().empty()) {
      return {};
    }

    std::ranges::sort(intervals, [](const auto &lhs, const auto &rhs) {
      return lhs.front() < rhs.front();
    });

    int left = intervals.front().front();
    int right = intervals.front().back();
    vector<vector<int>> result;
    for (const auto &interval : intervals) {
      const auto &left_pos = interval.front();
      const auto &right_pos = interval.back();

      if (left_pos <= right) {
        right = max(right, right_pos);
      } else {
        result.push_back({left, right});
        left = left_pos;
        right = right_pos;
      }
    }
    // last one
    result.push_back({left, right});

    return result;
  }
};