#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }

    int result = 1;
    unordered_set<char> set;
    set.insert(s.front());

    for (auto first = s.cbegin(), last = first + 1;;) {
      if (last == s.cend()) {
        result = max(result, static_cast<int>(last - first));
        break;
      }
      char ch = *last;
      if (set.contains(ch)) {
        result = max(result, static_cast<int>(last - first));
        while (*first != ch) {
          set.erase(*first);
          ++first;
        }
        set.erase(*first);
        ++first;
      } else {
        set.insert(ch);
        ++last;
      }
    }

    return result;
  }
};