#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {

    size_t left = 0;
    auto right = nums.size();
    while (left < right) {
      auto mid = left + (right - left) / 2;
      auto mid_num = nums[mid];
      if (mid_num == target) {
        return static_cast<int>(mid);
      }

      if (nums[left] <= mid_num) {
        if (nums[left] <= target && target < mid_num) {
          right = mid;
        } else {
          left = mid + 1;
        }
      } else {
        if (mid_num < target && target <= nums[right - 1]) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
    }

    return -1;
  }
};