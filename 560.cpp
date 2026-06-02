#include <cstddef>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int count = 0;
    int sum = 0;
    unordered_map<int, size_t> prefix_count;
    prefix_count.emplace(0, 1);
    for (const auto &num : nums) {
      sum += num;
      auto prefix = sum - k;
      auto iter = prefix_count.find(prefix);
      if (iter != prefix_count.end()) {
        count += iter->second;
      }
      prefix_count[sum] += 1;
    }

    return count;
  }
};