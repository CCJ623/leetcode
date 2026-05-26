#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    if (grid.empty() || grid.front().empty()) {
      return 0;
    }

    vector<vector<int>> dp(grid.size(), vector<int>(grid.front().size(), 0));
    {
      auto sum = 0;
      auto &first_row = dp.front();
      for (size_t i = 0; i < first_row.size(); ++i) {
        sum += grid.front()[i];
        first_row[i] = sum;
      }
    }
    {
      auto sum = 0;
      for (size_t row = 0; row < dp.size(); ++row) {
        sum += grid[row].front();
        dp[row].front() = sum;
      }
    }
    for (size_t row = 1; row < dp.size(); ++row) {
      for (size_t col = 1; col < dp[row].size(); ++col) {
        dp[row][col] = grid[row][col] + min(dp[row - 1][col], dp[row][col - 1]);
      }
    }

    return dp.back().back();
  }
};