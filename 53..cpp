#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    if (nums.empty()) {
      return {};
    }

    int result = numeric_limits<int>::min();
    int current_result = 0;
    for (const auto &num : nums) {
      if (current_result > 0) {
        current_result += num;
      } else {
        current_result = num;
      }
      result = max(result, current_result);
    }

    return result;
  }
};