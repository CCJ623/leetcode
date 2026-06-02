#include <cstddef>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    if (static_cast<int>(nums.size()) < k) {
      return {};
    }

    // store index
    deque<size_t> dq;
    for (size_t i = 0; static_cast<int>(i) < k; ++i) {
      if (dq.empty()) {
        dq.push_back(i);
        continue;
      }

      while (!dq.empty() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
    }

    vector<int> result;
    for (size_t left = 0, right = left + k - 1;;) {
      result.push_back(nums[dq.front()]);

      if (dq.front() == left) {
        dq.pop_front();
      }
      ++left;
      ++right;
      if (right >= nums.size()) {
        break;
      }
      while (!dq.empty() && nums[dq.back()] <= nums[right]) {
        dq.pop_back();
      }
      dq.push_back(right);
    }

    return result;
  }
};
