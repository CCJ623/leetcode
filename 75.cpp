#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    size_t red = 0;
    size_t white = 0;
    for (size_t curr = 0; curr < nums.size(); ++curr) {

      if (nums[curr] == 0) {
        swap(nums[red], nums[curr]);
        ++red;
        if (white < red) {
          white = red;
        }
      }

      if (nums[curr] == 1) {
        swap(nums[white], nums[curr]);
        ++white;
      }
    }
  }
};