#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    size_t left = 0;
    size_t right = height.size() - 1;
    int left_max = height[left];
    int right_max = height[right];
    int result = 0;

    while (left < right) {
      auto left_num = height[left];
      auto right_num = height[right];

      if (left_num < right_num) {
        result += left_max - left_num;
        ++left;
        left_max = max(left_max, height[left]);
      } else {
        result += right_max - right_num;
        --right;
        right_max = max(right_max, height[right]);
      }
    }

    return result;
  }
};