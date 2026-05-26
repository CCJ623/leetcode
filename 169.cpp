#include <vector>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int candidate = 0;
    size_t count = 0;

    for (const auto &num : nums) {
      if (count == 0) {
        candidate = num;
        count = 1;
      } else if (candidate == num) {
        ++count;
      } else {
        --count;
      }
    }

    return candidate;
  }
};