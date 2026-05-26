#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    if (nums.empty()) {
      return false;
    }

    auto sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) {
      return false;
    }

    auto target = sum / 2;
    if (ranges::max(nums) > target) {
      return false;
    }

    vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));
    dp[0][nums.front()] = true;
    for (auto &row : dp) {
      row.front() = true;
    }

    for (size_t row = 1; row < dp.size(); ++row) {
      size_t num = nums[row];
      for (size_t col = 1; col < num; ++col) {
        dp[row][col] = dp[row - 1][col];
      }
      for (size_t col = num; col < dp.front().size(); ++col) {
        dp[row][col] = (dp[row - 1][col] || dp[row - 1][col - nums[row]]);
      }
    }

    return dp.back().back();
  }
};