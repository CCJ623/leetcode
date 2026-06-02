#include <cstddef>
#include <limits>
#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> prefix(nums.size());
    vector<int> suffix(nums.size());

    int temp = 1;
    for (size_t i = 0; i < nums.size(); ++i) {
      temp *= nums[i];
      prefix[i] = temp;
    }
    temp = 1;
    for (size_t i = 0; i < nums.size(); ++i) {
      temp *= nums[nums.size() - i - 1];
      suffix[nums.size() - i - 1] = temp;
    }

    vector<int> result;
    for (size_t i = 0; i < nums.size(); ++i) {
      auto left_index = i - 1;
      auto right_index = i + 1;
      result.push_back((left_index == numeric_limits<size_t>::max()
                            ? 1
                            : prefix[left_index]) *
                       (right_index >= nums.size() ? 1 : suffix[right_index]));
    }

    return result;
  }
};
