#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }

    auto min_so_far = nums.front();
    auto max_so_far = min_so_far;
    auto result = max_so_far;
    for (const auto &num : nums | ranges::views::drop(1)) {
      auto new_max = max({min_so_far * num, max_so_far * num, num});
      auto new_min = min({min_so_far * num, max_so_far * num, num});
      max_so_far = new_max;
      min_so_far = new_min;
      result = max(result, max_so_far);
    }

    return result;
  }
};