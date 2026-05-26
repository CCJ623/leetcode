#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    size_t max_pos = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (i > max_pos) {
        return false;
      }

      max_pos = max(max_pos, i + nums[i]);
    }

    return true;
  }
};