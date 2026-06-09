#include <vector>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix.front().empty()) {
      return;
    }

    vector<bool> row_zero(matrix.size(), false);
    vector<bool> col_zero(matrix.front().size(), false);

    for (size_t row = 0; row < matrix.size(); ++row) {
      for (size_t col = 0; col < matrix[row].size(); ++col) {
        if (matrix[row][col] == 0) {
          row_zero[row] = col_zero[col] = true;
        }
      }
    }

    for (size_t row = 0; row < matrix.size(); ++row) {
      for (size_t col = 0; col < matrix[row].size(); ++col) {
        if (row_zero[row] || col_zero[col]) {
          matrix[row][col] = 0;
        }
      }
    }
  }
};
