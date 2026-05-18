#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty()) {
      return 0;
    }

    vector<vector<bool>> visited;
    for (size_t i = 0; i < grid.size(); ++i) {
      visited.emplace_back(grid.front().size(), false);
    }

    int count = 0;
    for (size_t i = 0; i < grid.size(); ++i) {
      for (size_t j = 0; j < grid.front().size(); ++j) {
        if (!visited[i][j] && grid[i][j] == '1') {
          bfs({i, j}, grid, visited);
          ++count;
        }
      }
    }

    return count;
  }

  void bfs(pair<int, int> coordinate, const vector<vector<char>> &grid,
           vector<vector<bool>> &visited) {
    queue<pair<int, int>> q;
    q.emplace(coordinate);
    while (!q.empty()) {
      auto [row, column] = q.front();
      q.pop();
      if (visited[row][column]) {
        continue;
      }

      visited[row][column] = true;

      auto next_coordinate = make_pair(row - 1, column);
      if (isCoordinateValid(next_coordinate, grid) &&
          !visited[next_coordinate.first][next_coordinate.second] &&
          grid[next_coordinate.first][next_coordinate.second] == '1') {
        q.push(next_coordinate);
      }

      next_coordinate = make_pair(row + 1, column);
      if (isCoordinateValid(next_coordinate, grid) &&
          !visited[next_coordinate.first][next_coordinate.second] &&
          grid[next_coordinate.first][next_coordinate.second] == '1') {
        q.push(next_coordinate);
      }

      next_coordinate = make_pair(row, column - 1);
      if (isCoordinateValid(next_coordinate, grid) &&
          !visited[next_coordinate.first][next_coordinate.second] &&
          grid[next_coordinate.first][next_coordinate.second] == '1') {
        q.push(next_coordinate);
      }

      next_coordinate = make_pair(row, column + 1);
      if (isCoordinateValid(next_coordinate, grid) &&
          !visited[next_coordinate.first][next_coordinate.second] &&
          grid[next_coordinate.first][next_coordinate.second] == '1') {
        q.push(next_coordinate);
      }
    }
  }

  bool isCoordinateValid(pair<int, int> coordinate,
                         const vector<vector<char>> &grid) {
    auto [row, column] = coordinate;
    return 0 <= row && row < static_cast<int>(grid.size()) && 0 <= column &&
           column < static_cast<int>(grid.front().size());
  }
};
