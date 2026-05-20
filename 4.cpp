#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // nums1 is always shorter than nums2
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    auto half_length = (nums1.size() + nums2.size()) / 2;
    size_t left = 0;
    auto right = nums1.size();
    while (left < right) {
      auto cut1 = left + (right - left) / 2;
      auto cut2 = half_length - cut1;
      if (nums1[cut1] < nums2[cut2 - 1]) {
        left = cut1 + 1;
      } else {
        right = cut1;
      }
    }

    auto cut2 = half_length - left;
    auto min1 = (left == 0 ? numeric_limits<int>::min() : nums1[left - 1]);
    auto max1 =
        (left >= nums1.size() ? numeric_limits<int>::max() : nums1[left]);
    auto min2 = (cut2 == 0 ? numeric_limits<int>::min() : nums2[cut2 - 1]);
    auto max2 =
        (cut2 >= nums2.size() ? numeric_limits<int>::max() : nums2[cut2]);

    if ((nums1.size() + nums2.size()) % 2 == 0) {
      return static_cast<double>(max(min1, min2) + min(max1, max2)) / 2;
    }

    return static_cast<double>(min(max1, max2));
  }
};