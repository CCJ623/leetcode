#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    size_t left = 0;
    size_t right = nums.size();

    while (left < right) {
      auto mid = (left + right) / 2;
      auto mid_num = nums[mid];
      if (mid_num < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }
};