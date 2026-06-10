#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix.front().empty()) {
      return false;
    }

    for (size_t row = 0, col = matrix.front().size() - 1;
         row != numeric_limits<size_t>::max() && row < matrix.size() &&
         col != numeric_limits<size_t>::max() && col < matrix.front().size();) {
      auto num = matrix[row][col];
      if (num == target) {
        return true;
      }

      if (num > target) {
        --col;
      } else {
        ++row;
      }
    }

    return false;
  }
};
