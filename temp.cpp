#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

using Direction = pair<long, long>;
using Coordinate = pair<long, long>;

struct Light {
  Coordinate coordinate_;
  Direction direction_;
};

const unordered_map<char, Direction> char_to_direction = {
    {'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}, {'D', {1, 0}}};
vector<vector<char>> grid;
vector<vector<long>> result;
vector<vector<set<Direction>>> visited;

void initVisited() {
  for (auto &row : visited) {
    for (auto &col : row) {
      col.clear();
    }
  }
}

bool isBarrier(const Coordinate &coordinate) {
  return grid[coordinate.first][coordinate.second] == '#';
}

bool isEmpty(const Coordinate &coordinate) {
  return grid[coordinate.first][coordinate.second] == '.';
}

bool isMirror(const Coordinate &coordinate) {
  auto element = grid[coordinate.first][coordinate.second];
  return element == '/' || element == '\\';
}

bool isBulb(const Coordinate &coordinate) {
  auto element = grid[coordinate.first][coordinate.second];
  return element == 'L' || element == 'R' || element == 'U' || element == 'D';
}

bool isCoordinateValid(const Coordinate &coordinate) {
  return 0 <= coordinate.first &&
         coordinate.first < static_cast<long>(grid.size()) &&
         0 <= coordinate.second &&
         coordinate.second < static_cast<long>(grid.front().size());
}

void dfs(const Light &light) {
  auto row = light.coordinate_.first;
  auto col = light.coordinate_.second;
  //cout << "current pos: " << row << " " << col << "\n";
  if (!isCoordinateValid(light.coordinate_)) {
    return;
  }
  if (isBarrier(light.coordinate_) || isBulb(light.coordinate_)) {
    return;
  }
  if (visited[row][col].find(light.direction_) != visited[row][col].end()) {
    // loop
    return;
  }
  if (isEmpty(light.coordinate_) && visited[row][col].empty()) {
    ++result[row][col];
  }

  visited[row][col].insert(light.direction_);

  if (isEmpty(light.coordinate_)) {
    // empty
    auto next_light = light;
    next_light.coordinate_.first += light.direction_.first;
    next_light.coordinate_.second += light.direction_.second;
    dfs(next_light);
  } else {
    // mirror
    auto next_light = light;
    if (grid[row][col] == '/') {
      // "/"
      if (char_to_direction.at('L') == light.direction_) {
        next_light.direction_ = char_to_direction.at('D');
      } else if (char_to_direction.at('R') == light.direction_) {
        next_light.direction_ = char_to_direction.at('U');
      } else if (char_to_direction.at('U') == light.direction_) {
        next_light.direction_ = char_to_direction.at('R');
      } else if (char_to_direction.at('D') == light.direction_) {
        next_light.direction_ = char_to_direction.at('L');
      }
    } else {
      // "\"
      if (char_to_direction.at('L') == light.direction_) {
        next_light.direction_ = char_to_direction.at('U');
      } else if (char_to_direction.at('R') == light.direction_) {
        next_light.direction_ = char_to_direction.at('D');
      } else if (char_to_direction.at('U') == light.direction_) {
        next_light.direction_ = char_to_direction.at('L');
      } else if (char_to_direction.at('D') == light.direction_) {
        next_light.direction_ = char_to_direction.at('R');
      }
    }
    next_light.coordinate_.first += next_light.direction_.first;
    next_light.coordinate_.second += next_light.direction_.second;
    dfs(next_light);
  }

  visited[row][col].erase(light.direction_);
}

int main() {
  long n, m;
  cin >> n >> m;
  grid.resize(n);
  result.resize(n, vector<long>(m, -1));
  visited.resize(n, vector<set<Direction>>(m));
  for (long i = 0; i < n; ++i) {
    string str;
    cin >> str;
    for (long j = 0; j < m; ++j) {
      grid[i].push_back(str[j]);
      if (str[j] == '.') {
        result[i][j] = 0;
      }
    }
  }

  for (size_t row = 0; row < grid.size(); ++row) {
    for (size_t col = 0; col < grid.front().size(); ++col) {
      if (!isBulb({row, col})) {
        continue;
      }

      initVisited();
      auto direction = char_to_direction.at(grid[row][col]);
      auto next_pos =
          pair<long, long>{row + direction.first, col + direction.second};
      Light light{next_pos, direction};
      dfs(light);
    }
  }

  for (const auto &row : result) {
    for (const auto &col : row) {
      cout << col << " ";
    }
    cout << "\n";
  }
}