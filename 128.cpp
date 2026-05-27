#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> hash_set{nums.begin(), nums.end()};
    int result = 0;
    for (const auto &num : hash_set) {
      if (hash_set.contains(num - 1)) {
        continue;
      }

      auto next = num + 1;
      for (; hash_set.contains(next); ++next) {
      }
      result = max(result, next - num);
    }

    return result;
  }
};