#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  // int trap(vector<int> &height) {
  //   if (height.empty()) {
  //     return 0;
  //   }

  //   vector<int> left_max(height.size(), numeric_limits<int>::min());
  //   vector<int> right_max(height.size(), numeric_limits<int>::min());

  //   // init
  //   {
  //     int curr_max = numeric_limits<int>::min();
  //     for (size_t i = 0; i < height.size(); ++i) {
  //       if (height[i] > curr_max) {
  //         curr_max = height[i];
  //       }
  //       left_max[i] = curr_max;
  //     }

  //     curr_max = numeric_limits<int>::min();
  //     for (size_t i = height.size() - 1; i != numeric_limits<size_t>::max();
  //          --i) {
  //       if (height[i] > curr_max) {
  //         curr_max = height[i];
  //       }
  //       right_max[i] = curr_max;
  //     }
  //   }

  //   int result = 0;
  //   for (size_t i = 0; i < height.size(); ++i) {
  //     auto min_max = min(left_max[i], right_max[i]);
  //     if (height[i] > min_max) {
  //       continue;
  //     }
  //     result += (min_max - height[i]);
  //   }

  //   return result;
  // }

  int trap(vector<int> &height) {
    if (height.empty()) {
      return 0;
    }

    int result = 0;
    int left_max = 0;
    int right_max = 0;
    for (size_t left = 0, right = height.size() - 1; left < right;) {
      if (height[left] < height[right]) {
        if (height[left] > left_max) {
          left_max = height[left];
        } else {
          result += (left_max - height[left]);
        }
        ++left;
      } else {
        if (height[right] > right_max) {
          right_max = height[right];
        } else {
          result += (right_max - height[right]);
        }
        --right;
      }
    }

    return result;
  }
};