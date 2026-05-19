#include <algorithm>
#include <print>
#include <ranges>
#include <span>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    column_queen_.resize(n, false);
    diagonal_up_.resize(n * 2 - 1, false);
    diagonal_down_.resize(n * 2 - 1, false);
    down_bias_ = n - 1;
    vector<vector<string>> result;
    auto order = ranges::views::iota(0, n) | ranges::to<vector<int>>();
    vector<int> path;

    dfs(order, path, result);
    return result;
  }

private:
  void dfs(span<int> order, vector<int> &path, vector<vector<string>> &result) {
    // println("{}", path);
    if (order.empty()) {
      vector<string> temp{path.size(), string(path.size(), '.')};
      for (size_t row = 0; row < path.size(); ++row) {
        temp[row][path[row]] = 'Q';
      }
      result.push_back(temp);
      return;
    }

    auto row = path.size();
    for (size_t i = 0; i < order.size(); ++i) {
      auto column = order[i];
      if (!column_queen_[column] && !diagonal_up_[row + column] &&
          !diagonal_down_[down_bias_ + row - column]) {
        swap(order.front(), order[i]);
        path.push_back(order.front());
        column_queen_[column] = true;
        diagonal_up_[row + column] = true;
        diagonal_down_[down_bias_ + row - column] = true;

        dfs(order.subspan(1), path, result);

        column_queen_[column] = false;
        diagonal_up_[row + column] = false;
        diagonal_down_[down_bias_ + row - column] = false;
        path.pop_back();
        swap(order.front(), order[i]);
      }
    }
  }

  vector<bool> column_queen_;
  vector<bool> diagonal_up_;
  vector<bool> diagonal_down_;
  int down_bias_;
};

int main() {
  auto result = Solution{}.solveNQueens(4);
  ranges::for_each(result, [](const auto &result) {
    println("---------------------");
    for (const auto &row : result) {
      println("{}", row);
    }
    println("---------------------");
  });
}
