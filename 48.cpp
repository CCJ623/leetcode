#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix.front().empty()) {
      return;
    }

    auto get_line_view = [&matrix](size_t row_index, size_t left,
                                   size_t right) {
      return matrix[row_index] | ranges::views::take(right) |
             ranges::views::drop(left);
    };
    auto get_column_view = [&matrix](size_t column_index, size_t top,
                                     size_t bottom) {
      return matrix | ranges::views::take(bottom) | ranges::views::drop(top) |
             ranges::views::transform([column_index](auto &row) -> auto & {
               return row[column_index];
             });
    };

    for (size_t i = 0; i < matrix.size() / 2; ++i) {
      auto end_index = matrix.front().size() - i;
      auto take_size = end_index - i - 1;

      auto top_view =
          get_line_view(i, i, end_index) | ranges::views::take(take_size);
      auto right_view = get_column_view(end_index - 1, i, end_index) |
                        ranges::views::take(take_size);
      auto bottom_view = get_line_view(end_index - 1, i, end_index) |
                         views::reverse | ranges::views::take(take_size);
      auto left_view = get_column_view(i, i, end_index) | views::reverse |
                       ranges::views::take(take_size);

      for (auto [top, right, bottom, left] :
           ranges::views::zip(top_view, right_view, bottom_view, left_view)) {
        auto temp = top;
        top = left;

        swap(temp, right);
        swap(temp, bottom);
        swap(temp, left);
      }
    }
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution{}.rotate(matrix);
}
