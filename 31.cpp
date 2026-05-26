#include <algorithm>
#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    if (nums.size() <= 1) {
      return;
    }

    int i = nums.size() - 2;
    for (; i >= 0 && nums[i] >= nums[i + 1]; --i) {
    }

    if (i < 0) {
      ranges::reverse(nums);
      return;
    }

    int j = nums.size() - 1;
    for (; j > i && nums[j] <= nums[i]; --j) {
    }
    swap(nums[i], nums[j]);
    ranges::reverse(nums | ranges::views::drop(i + 1));
    return;
  }
};