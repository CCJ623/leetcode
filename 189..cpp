#include <algorithm>
#include <span>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    if (nums.empty()) {
      return;
    }

    reverse(nums.begin(), nums.end());
    auto separator = k % nums.size();
    reverse(nums.begin(), nums.begin() + separator);
    reverse(nums.begin() + separator, nums.end());
  }
};