#include <vector>

using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    if (nums.empty() || nums.size() == 1) {
      return 0;
    }

    int jump_count = 1;
    size_t end = 1;
    size_t max_pos = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (i == end) {
        ++jump_count;
        end = max_pos + 1;
      }
      max_pos = max(max_pos, i + nums[i]);
      if (max_pos >= nums.size() - 1) {
        break;
      }
    }

    return jump_count;
  }
};