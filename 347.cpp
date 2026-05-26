#include <cstddef>
#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    if (nums.size() < static_cast<size_t>(k)) {
      return {};
    }

    unordered_map<int, size_t> hash_table;
    for (const auto &num : nums) {
      hash_table[num] += 1;
    }

    auto comparator = [](const pair<int, size_t> &lhs,
                         const pair<int, size_t> &rhs) {
      return lhs.second > rhs.second;
    };
    priority_queue<pair<int, size_t>, vector<pair<int, size_t>>,
                   decltype(comparator)>
        pq;
    for (const auto &pair : hash_table) {
      if (pq.size() < static_cast<size_t>(k)) {
        pq.push(pair);
        continue;
      }

      if (comparator(pair, pq.top())) {
        pq.pop();
        pq.push(pair);
      }
    }

    vector<int> result;
    while (!pq.empty()) {
      auto [num, count] = pq.top();
      pq.pop();
      result.push_back(num);
    }

    return result;
  }
};