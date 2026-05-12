#include <algorithm>
#include <deque>
#include <iterator>
#include <print>
#include <type_traits>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    if (static_cast<int>(nums.size()) < k) {
      return {};
    }
    vector<int> result;
    result.reserve(nums.size() - k + 1);
    deque<decay_t<decltype(nums)>::const_iterator> d;
    for (auto right = nums.cbegin(); right < nums.cend(); ++right) {
      auto left = right - k;
      // pop left
      if (left >= nums.cbegin() && left == d.front()) {
        d.pop_front();
      }

      // pop num < right
      while (!d.empty() && *d.back() <= *right) {
        d.pop_back();
      }

      // push right
      d.push_back(right);

      if (right >= nums.cbegin() + k - 1) {
        result.push_back(*d.front());
      }
    }

    return result;
  }
};

int main() {
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  Solution{}.maxSlidingWindow(nums, k);
}
