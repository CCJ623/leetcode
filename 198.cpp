#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }

    int prev_one = nums.front();
    int prev_two = 0;
    for (size_t i = 1; i < nums.size(); ++i) {
      auto new_result = max(prev_one, prev_two + nums[i]);
      prev_two = prev_one;
      prev_one = new_result;
    }

    return prev_one;
  }
};