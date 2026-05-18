#include <array>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

class Solution {
  using CoordinateType = pair<int, int>;

public:
  bool exist(vector<vector<char>> &board, string word) {
    vector<vector<bool>> visited(board.size(),
                                 vector<bool>(board.front().size(), false));

    for (size_t row = 0; row < board.size(); ++row) {
      for (size_t column = 0; column < board.front().size(); ++column) {
        if (dfs({row, column}, board, visited, word) == true) {
          return true;
        }
      }
    }
    return false;
  }

private:
  auto dfs(CoordinateType coordinate, vector<vector<char>> &board,
           vector<vector<bool>> &visited, string_view suffix) -> bool {
    if (suffix.empty()) {
      return true;
    }

    auto [row, column] = coordinate;
    if (row < 0 || row >= static_cast<int>(board.size()) || column < 0 ||
        column >= static_cast<int>(board.front().size())) {
      return false;
    }
    if (visited[row][column]) {
      return false;
    }
    if (board[row][column] != suffix.front()) {
      return false;
    }

    visited[row][column] = true;

    for (const auto &direction : kDirections) {
      auto next_coordinate = coordinate;
      next_coordinate.first += direction.first;
      next_coordinate.second += direction.second;

      if (dfs(next_coordinate, board, visited, suffix.substr(1)) == true) {
        return true;
      }
    }

    visited[row][column] = false;

    return false;
  }

  static constexpr array<CoordinateType, 4> kDirections{
      {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}};
};