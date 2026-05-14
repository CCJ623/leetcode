#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty()) {
      return false;
    }

    for (size_t row = 0, column = matrix.front().size() - 1;;) {
      if (row >= matrix.size() || column == numeric_limits<size_t>::max()) {
        return false;
      }
      const auto &num = matrix[row][column];
      if (num == target) {
        return true;
      }

      if (target < num) {
        --column;
      } else {
        ++row;
      }
    }
  }
};
