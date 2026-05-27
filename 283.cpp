#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    size_t first = 0;
    for (; first < nums.size() && nums[first] != 0; ++first) {
    }
    size_t second = first + 1;
    for (; second < nums.size() && nums[second] == 0; ++second) {
    }

    for (; second < nums.size();) {
      swap(nums[first], nums[second]);
      for (; first < nums.size() && nums[first] != 0; ++first) {
      }
      for (; second < nums.size() && nums[second] == 0; ++second) {
      }
    }
  }
};