#include <vector>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    size_t left = 0;
    size_t right = nums.size();

    while (left < right) {
      auto mid = left + (right - left) / 2;
      auto mid_num = nums[mid];
      if (mid_num < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    if (left >= nums.size()) {
      return {-1, -1};
    }

    auto result_left = left;
    right = nums.size();
    while (left < right) {
      auto mid = left + (right - left) / 2;
      auto mid_num = nums[mid];
      if (mid_num <= target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    if (result_left == left) {
      return {-1, -1};
    }

    return {static_cast<int>(result_left), static_cast<int>(left - 1)};
  }
};