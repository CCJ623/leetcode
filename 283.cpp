#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    if (nums.empty()) {
      return;
    }
    auto find_not_zero = [](const auto &num) { return num != 0; };
    for (auto first = find(nums.begin(), nums.end(), 0),
              second = find_if(first, nums.end(), find_not_zero);
         second < nums.cend(); first = find(first + 1, nums.end(), 0),
              second = find_if(first, nums.end(), find_not_zero)) {
      swap(*first, *second);
    }
  }
};