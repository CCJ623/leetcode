#include <array>
#include <cstddef>
#include <iterator>
#include <string>
#include <string_view>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    if (s.empty() || t.empty() || s.size() < t.size()) {
      return {};
    }

    array<size_t, 128> target_count;
    target_count.fill(0);
    array<size_t, 128> window_count;
    window_count.fill(0);

    for (const auto &ch : t) {
      ++target_count[ch];
    }

    size_t need_count = t.size();
    auto left = s.cbegin();
    auto right = s.cbegin();
    while (need_count > 0) {
      if (right >= s.cend()) {
        return {};
      }
      if (window_count[*right] < target_count[*right]) {
        --need_count;
      }
      ++window_count[*right];
      ++right;
    }

    string_view result{left, right};
    while (right <= s.cend()) {
      if (need_count > 0) {
        if (window_count[*right] < target_count[*right]) {
          --need_count;
        }
        ++window_count[*right];
        ++right;
        continue;
      }

      auto left_char = *left;
      if (--window_count[left_char] < target_count[left_char]) {
        ++need_count;
      }
      ++left;
      if (need_count == 0 &&
          distance(left, right) < static_cast<long>(result.size())) {
        result = {left, right};
      }
    }

    return string{result};
  }
};

int main() {
  string s = "ab";
  string t = "a";
  Solution{}.minWindow(s, t);
}
