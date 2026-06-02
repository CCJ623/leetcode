#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    for (auto &num : nums) {
      while (1 <= num && num <= static_cast<int>(nums.size()) &&
             nums[num - 1] != num) {
        swap(num, nums[num - 1]);
      }
    }

    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] != static_cast<int>(i + 1)) {
        return i + 1;
      }
    }

    return nums.size() + 1;
  }
};