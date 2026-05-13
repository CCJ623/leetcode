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

    auto nums_span = span{nums};
    auto target_pos = (k % nums.size());
    ranges::reverse(nums);
    auto first_span = nums_span.subspan(0, target_pos);
    auto second_span = nums_span.subspan(target_pos);
    ranges::reverse(first_span);
    ranges::reverse(second_span);
  }
};