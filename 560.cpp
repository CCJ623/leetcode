#include <cstddef>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int count = 0;
    int sum = 0;
    unordered_map<int, size_t> hash_table;
    hash_table.insert({0, 1});
    for (const auto &num : nums) {
      sum += num;
      auto iter = hash_table.find(sum - k);
      if (iter != hash_table.cend()) {
        count += iter->second;
      }
      ++hash_table[sum];
    }
    return count;
  }
};