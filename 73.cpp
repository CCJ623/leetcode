#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix.front().empty()) {
      return;
    }

    vector<bool> is_row_zero(matrix.size(), false);
    vector<bool> is_column_zero(matrix.front().size(), false);

    for (const auto &[row_index, row] :
         ranges::views::zip(views::iota(0), matrix)) {
      for (const auto &[column_index, num] :
           ranges::views::zip(views::iota(0), row)) {
        if (num == 0) {
          is_row_zero[row_index] = true;
          is_column_zero[column_index] = true;
        }
      }
    }

    for (auto [row_index, row] : ranges::views::zip(views::iota(0), matrix)) {
      for (auto [column_index, num] : ranges::views::zip(views::iota(0), row)) {
        if (is_row_zero[row_index] || is_column_zero[column_index]) {
          num = 0;
        }
      }
    }
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  Solution{}.setZeroes(matrix);
}