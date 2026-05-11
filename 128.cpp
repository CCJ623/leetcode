#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    set<int> s{nums.cbegin(), nums.cend()};
    int result = 0;
    for (auto num : s) {
      if (s.contains(num - 1)) {
        continue;
      }
      int current = 1;
      while (s.contains(++num)) {
        ++current;
      }
      result = max(result, current);
    }
    return result;
  }
};