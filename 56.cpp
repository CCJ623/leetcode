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
      return lhs.front() < rhs.front();
    });
    vector<vector<int>> result;
    auto left = intervals.front().front();
    auto right = intervals.front().back();
    for (const auto &interval : intervals) {
      if (interval.front() <= right) {
        right = max(right, interval.back());
      } else {
        result.push_back({left, right});
        left = interval.front();
        right = interval.back();
      }
    }

    result.push_back({left, right});
    return result;
  }
};