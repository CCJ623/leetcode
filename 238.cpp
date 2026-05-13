#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    if (nums.empty()) {
      return {};
    }

    vector<int> result;
    int temp = 1;

    // calculate left prefix and store in result
    for (const auto &num : nums) {
      temp *= num;
      result.push_back(temp);
    }

    // calculate result, store current right prefix in temp
    temp = 1;
    for (const auto &[index, num] :
         std::views::zip(ranges::views::iota(0), nums) | std::views::reverse) {
      if (index > 0) {
        result[index] = temp * result[index - 1];
        temp *= num;
      }
    }
    // last one
    result.front() = temp;

    return result;
  }
};

int main() {
  vector<int> nums = {1, 2, 3};
  Solution{}.productExceptSelf(nums);
}