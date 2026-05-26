#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }

    int result = 1;
    vector<size_t> dp;
    dp.reserve(nums.size());
    dp.push_back(1);
    for (size_t i = 1; i < nums.size(); ++i) {
      size_t max_count = 1;
      for (size_t j = 0; j < i; ++j) {
        if (nums[j] >= nums[i]) {
          continue;
        }

        max_count = max(max_count, dp[j] + 1);
      }
      dp.push_back(max_count);
      result = max(result, static_cast<int>(dp.back()));
    }

    return result;
  }
};