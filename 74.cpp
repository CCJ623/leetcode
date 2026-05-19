#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix.front().empty()) {
      return false;
    }

    size_t left = 0;
    size_t right = matrix.size();

    while (left < right) {
      auto mid = left + (right - left) / 2;
      auto mid_num = matrix[mid].back();
      if (mid_num < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    if (left >= matrix.size()) {
      return false;
    }

    const auto &row = matrix[left];
    left = 0;
    right = row.size();

    while (left < right) {
      auto mid = left + (right - left) / 2;
      auto mid_num = row[mid];
      if (mid_num < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left < row.size() && row[left] == target;
  }
};