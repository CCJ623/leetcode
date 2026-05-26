#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<size_t>> dp(m, vector<size_t>(n, 0));
    ranges::fill(dp.front(), 1);
    for (auto &row : dp) {
      row.front() = 1;
    }

    for (size_t row = 1; row < dp.size(); ++row) {
      for (size_t col = 1; col < dp.front().size(); ++col) {
        dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
      }
    }

    return dp.back().back();
  }
};