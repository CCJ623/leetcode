#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int result = numeric_limits<int>::min();
    int min_prefix = 0;
    int sum = 0;
    for (const auto &num : nums) {
      sum += num;
      result = max(result, sum - min_prefix);
      if (sum < min_prefix) {
        min_prefix = sum;
      }
    }

    return result;
  }
};