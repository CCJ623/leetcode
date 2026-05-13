#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    if (nums.empty()) {
      return 1;
    }

    auto nums_with_index = ranges::views::zip(ranges::views::iota(0), nums);
    for (auto [index, num] : nums_with_index) {
      while (0 < num && num <= static_cast<int>(nums.size()) &&
             nums[num - 1] != num) {
        swap(nums[num - 1], num);
      }
    }

    for (const auto &[index, num] : nums_with_index) {
      if (num != index + 1) {
        return index + 1;
      }
    }

    return nums.size() + 1;
  }
};