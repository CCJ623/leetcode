#include <cstddef>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) {
      return {};
    }

    unordered_map<char, size_t> p_count;
    for (const auto &ch : p) {
      p_count[ch] += 1;
    }

    unordered_map<char, size_t> s_count;
    vector<int> result;
    size_t start = 0, end = 0;
    for (; end < p.size(); ++end) {
      s_count[s[end]] += 1;
    }

    auto success = [&p_count, &s_count]() -> bool {
      for (const auto &[ch, count] : p_count) {
        if (s_count[ch] != count) {
          return false;
        }
      }
      return true;
    };

    if (success()) {
      result.push_back(start);
    }

    for (; end < s.size(); ++start, ++end) {
      s_count[s[end]] += 1;
      s_count[s[start]] -= 1;
      if (success()) {
        result.push_back(start + 1);
      }
    }

    return result;
  }
};
