#include <cstddef>
#include <limits>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    if (s.size() < t.size()) {
      return "";
    }

    size_t result_left = numeric_limits<size_t>::max();
    size_t result_right = numeric_limits<size_t>::max();
    unordered_map<char, size_t> t_count;
    for (const auto &ch : t) {
      t_count[ch] += 1;
    }
    unordered_map<char, size_t> window_count;

    auto varify = [&t_count, &window_count]() {
      for (const auto &[ch, count] : t_count) {
        if (!window_count.contains(ch) || window_count[ch] < count) {
          return false;
        }
      }
      return true;
    };

    window_count[s.front()] += 1;
    for (size_t left = 0, right = 0;;) {
      if (varify()) {
        if (result_left == numeric_limits<size_t>::max() ||
            result_right == numeric_limits<size_t>::max() ||
            right - left < result_right - result_left) {
          result_left = left;
          result_right = right;
        }

        window_count[s[left]] -= 1;
        ++left;
        continue;
      }

      ++right;
      if (right >= s.size()) {
        break;
      }
      window_count[s[right]] += 1;
    }

    if (result_left == numeric_limits<size_t>::max() ||
        result_right == numeric_limits<size_t>::max()) {
      return "";
    }

    return s.substr(result_left, result_right - result_left + 1);
  }
};
