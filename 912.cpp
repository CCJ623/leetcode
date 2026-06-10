#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    helper(nums, 0, nums.size());
    return nums;
  }

private:
  void helper(vector<int> &nums, size_t begin, size_t end) {
    if (end - begin <= 1) {
      return;
    }

    auto random_index = begin + rand() % (end - begin);
    swap(nums[begin], nums[random_index]);
    auto pivot = nums[begin];
    auto left = begin, right = end - 1;
    while (left < right) {
      while (left < right && nums[right] >= pivot) {
        --right;
      }
      while (left < right && nums[left] <= pivot) {
        ++left;
      }
      swap(nums[left], nums[right]);
    }

    swap(nums[begin], nums[left]);
    helper(nums, begin, left);
    helper(nums, left + 1, end);
  }
};