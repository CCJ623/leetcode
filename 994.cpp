#include <array>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    using CoordinateType = pair<int, int>;

    int time_count = 0;
    int fresh_count = 0;
    queue<CoordinateType> q;
    for (size_t i = 0; i < grid.size(); ++i) {
      for (size_t j = 0; j < grid.front().size(); ++j) {
        auto unit = grid[i][j];
        if (unit == 1) {
          ++fresh_count;
        } else if (unit == 2) {
          q.emplace(i, j);
        }
      }
    }

    while (fresh_count > 0 && !q.empty()) {
      ++time_count;
      auto queue_size = q.size();
      for (size_t i = 0; i < queue_size; ++i) {
        auto coordinate = q.front();
        q.pop();

        auto [row, column] = coordinate;
        for (const auto &direction : kDirections) {
          auto next_coordinate = coordinate;
          next_coordinate.first += direction.first;
          next_coordinate.second += direction.second;

          if (isCoordinateValid(next_coordinate, grid) &&
              grid[next_coordinate.first][next_coordinate.second] == 1) {
            q.push(next_coordinate);
            grid[next_coordinate.first][next_coordinate.second] = 2;
            --fresh_count;

            // println("rot:{}", next_coordinate);
          }
        }
      }
    }

    if (fresh_count > 0) {
      return -1;
    }
    return time_count;
  }

private:
  bool isCoordinateValid(pair<int, int> coordinate,
                         const vector<vector<int>> &grid) {
    auto [row, column] = coordinate;
    return 0 <= row && row < static_cast<int>(grid.size()) && 0 <= column &&
           column < static_cast<int>(grid.front().size());
  }

  static constexpr array<pair<int, int>, 4> kDirections = {
      {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
};

int main() {
  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  Solution{}.orangesRotting(grid);
}