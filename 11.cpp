#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int result = 0;
    size_t left = 0;
    size_t right = height.size() - 1;
    for (; left < right;) {
      auto left_height = height[left];
      auto right_height = height[right];
      result = max(result, min(left_height, right_height) *
                               static_cast<int>((right - left)));
      if (left_height < right_height) {
        ++left;
      } else {
        --right;
      }
    }
    return result;
  }
};