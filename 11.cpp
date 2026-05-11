#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int result = 0;
    for (auto first = height.cbegin(), last = height.cend() - 1;
         first < last;) {
      result = max(result, static_cast<int>(last - first) * min(*first, *last));
      if (*first < *last) {
        ++first;
      } else {
        --last;
      }
    }
    return result;
  }
};