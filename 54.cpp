#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix.front().empty()) {
      return {};
    }

    auto get_line_view = [&matrix](size_t row_index, size_t left,
                                   size_t right) {
      return matrix[row_index] | ranges::views::take(right) |
             ranges::views::drop(left);
    };
    auto get_column_view = [&matrix](size_t column_index, size_t top,
                                     size_t bottom) {
      return matrix | ranges::views::take(bottom) | ranges::views::drop(top) |
             ranges::views::transform(
                 [column_index](auto &row) { return row[column_index]; });
    };

    vector<int> result;
    result.reserve(matrix.size() * matrix.front().size());

    size_t top = 0;
    size_t bottom = matrix.size();
    size_t left = 0;
    size_t right = matrix.front().size();

    auto go_right = [&get_line_view, &result, &top, &left, &right]() {
      for (const auto &num : get_line_view(top, left, right)) {
        result.push_back(num);
      }
      ++top;
    };
    auto go_down = [&get_column_view, &result, &top, &bottom, &right]() {
      for (const auto &num : get_column_view(right - 1, top, bottom)) {
        result.push_back(num);
      }
      --right;
    };
    auto go_left = [&get_line_view, &result, &bottom, &left, &right]() {
      for (const auto &num :
           get_line_view(bottom - 1, left, right) | views::reverse) {
        result.push_back(num);
      }
      --bottom;
    };
    auto go_up = [&get_column_view, &result, &top, &bottom, &left]() {
      for (const auto &num :
           get_column_view(left, top, bottom) | views::reverse) {
        result.push_back(num);
      }
      ++left;
    };

    while (true){
        if (top >= bottom){
            break;
        }
        go_right();
        if (left >= right){
            break;
        }
        go_down();
        if (top >= bottom){
            break;
        }
        go_left();
        if (left >= right){
            break;
        }
        go_up();
    }

    return result;
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution{}.spiralOrder(matrix);
}
