#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    if (nums.empty()) {
      return -1;
    }

    size_t left = 0;
    auto right = nums.size();
    while (left < right) {
      auto mid = left + (right - left) / 2;
      auto mid_num = nums[mid];
      if (mid_num > nums.back()) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return nums[left];
  }
};