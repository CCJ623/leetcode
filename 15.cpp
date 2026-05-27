#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3) {
      return {};
    }

    vector<vector<int>> result;
    ranges::sort(nums);
    for (size_t i = 0; i < nums.size() - 2;) {
      auto curr_num = nums[i];
      if (curr_num > 0) {
        break;
      }

      size_t left = i + 1;
      size_t right = nums.size() - 1;
      auto target_num = 0 - curr_num;
      for (; left < right;) {
        auto left_num = nums[left];
        auto right_num = nums[right];
        if (left_num + right_num == target_num) {
          result.push_back({curr_num, left_num, right_num});
          for (; nums[left] == left_num && left < right; ++left)
            ;
          for (; nums[right] == right_num && left < right; --right)
            ;
        } else if (left_num + right_num < target_num) {
          ++left;
        } else {
          --right;
        }
      }

      for (; nums[i] == curr_num && i < nums.size() - 2; ++i)
        ;
      ;
    }

    return result;
  }
};