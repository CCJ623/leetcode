#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  int numSquares(int n) {
    if (n == 0) {
      return 0;
    }

    vector<size_t> dp;
    dp.reserve(n + 1);
    dp.push_back(0);

    for (int i = 1; i <= n; ++i) {

      size_t min_count = numeric_limits<size_t>::max();
      for (int j = 1; j * j <= i; ++j) {
        min_count = min(min_count, 1 + dp[i - j * j]);
      }
      dp.push_back(min_count);
    }

    return dp.back();
  }
};