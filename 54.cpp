#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix.front().empty()) {
      return {};
    }

    long top = -1;
    long bottom = matrix.size();
    long left = -1;
    long right = matrix.front().size();
    vector<int> result;
    result.reserve(matrix.size() * matrix.front().size());

    for (;;) {
      if (top + 1 >= bottom || left + 1 >= right) {
        break;
      }
      for (auto row = top + 1, col = left + 1; col < right; ++col) {
        result.push_back(matrix[row][col]);
      }
      top += 1;

      if (top + 1 >= bottom || left + 1 >= right) {
        break;
      }
      for (auto row = top + 1, col = right - 1; row < bottom; ++row) {
        result.push_back(matrix[row][col]);
      }
      right -= 1;

      if (top + 1 >= bottom || left + 1 >= right) {
        break;
      }
      for (auto row = bottom - 1, col = right - 1; col > left; --col) {
        result.push_back(matrix[row][col]);
      }
      bottom -= 1;

      if (top + 1 >= bottom || left + 1 >= right) {
        break;
      }
      for (auto row = bottom - 1, col = left + 1; row > top; --row) {
        result.push_back(matrix[row][col]);
      }
      left += 1;
    }

    return result;
  }
};
