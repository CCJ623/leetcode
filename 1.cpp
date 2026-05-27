#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // vector<int> twoSum(vector<int>& nums, int target) {
  //     // <num, index>
  //     unordered_map<int, size_t> hash_table;
  //     for (size_t i =0; i < nums.size(); ++i){
  //         auto num = nums[i];
  //         auto iter = hash_table.find(target-num);
  //         if (iter != hash_table.cend()){
  //             return {static_cast<int>(iter->second), static_cast<int>(i)};
  //         }
  //         hash_table[num] = i;
  //     }
  //     return {};
  // }

  vector<int> twoSum(vector<int> &nums, int target) {
    if (nums.size() < 2) {
      return {};
    }

    vector<pair<int, int>> nums_with_id;
    nums_with_id.reserve(nums.size());
    for (size_t i = 0; i < nums.size(); ++i) {
      nums_with_id.emplace_back(nums[i], i);
    }
    ranges::sort(nums_with_id, [](const auto &lhs, const auto &rhs) {
      return lhs.first < rhs.first;
    });

    int left = 0;
    int right = nums_with_id.size() - 1;
    while (left < right) {
      auto sum = nums_with_id[left].first + nums_with_id[right].first;
      if (sum == target) {
        return {nums_with_id[left].second, nums_with_id[right].second};
      }
      if (sum < target) {
        ++left;
      } else {
        --right;
      }
    }
    return {};
  }
};