#include <cstddef>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<size_t> dp;
    dp.reserve(amount + 1);
    dp.push_back(0);
    for (int i = 1; i <= amount; ++i) {
      auto min_count = numeric_limits<size_t>::max();
      for (const auto &coin : coins) {
        auto index = i - coin;
        if (index < 0 || dp[index] == numeric_limits<size_t>::max()) {
          continue;
        }

        min_count = min(min_count, dp[index] + 1);
      }
      dp.push_back(min_count);
    }

    if (dp.back() == numeric_limits<size_t>::max()) {
      return -1;
    }

    return dp.back();
  }
};