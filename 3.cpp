#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }

    unordered_set<char> set;
    int result = 0;
    for (size_t left = 0, right = 0; right < s.size();) {
      auto ch = s[right];
      if (set.contains(ch)) {
        set.erase(s[left]);
        ++left;
      } else {
        result = max(result, static_cast<int>(right - left + 1));
        set.insert(ch);
        ++right;
      }
    }

    return result;
  }
};