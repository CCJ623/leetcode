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

    std::sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for (size_t i = 0; i < nums.size() - 2;) {
      if (nums[i] > 0) {
        break;
      }

      auto curr_num = nums[i];
      size_t left = i + 1;
      size_t right = nums.size() - 1;
      while (left < right) {
        auto left_num = nums[left];
        auto right_num = nums[right];
        if (right_num < 0) {
          break;
        }

        auto sum = curr_num + left_num + right_num;
        if (sum == 0) {
          result.push_back({curr_num, left_num, right_num});
          for (; left < right && nums[left] == left_num; ++left)
            ;
          for (; left < right && nums[right] == right_num; --right)
            ;
        } else if (sum > 0) {
          for (; left < right && nums[right] == right_num; --right)
            ;
        } else {
          // sum < 0
          for (; left < right && nums[left] == left_num; ++left)
            ;
        }
      }

      for (; i < nums.size() - 2 && nums[i] == curr_num; ++i)
        ;
    }

    return result;
  }
};