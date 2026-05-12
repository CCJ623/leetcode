#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    if (s.empty() || p.empty() || s.size() < p.size()) {
      return {};
    }
    vector<int> result;
    unordered_map<char, size_t> s_count;
    for (const auto &ch : p) {
      ++s_count[ch];
    }

    unordered_map<char, size_t> p_count;
    for (auto iter = s.cbegin(); iter < s.cbegin() + p.size(); ++iter) {
      ++p_count[*iter];
    }

    for (auto iter = s.cbegin(); iter <= s.cend() - p.size(); ++iter) {
      if (s_count == p_count) {
        result.push_back(distance(s.cbegin(), iter));
      }
      auto next_iter = iter + p.size();
      if (next_iter < s.cend()) {
        if (p_count[*iter] == 1) {
          p_count.erase(*iter);
        } else {
          --p_count[*iter];
        }
        ++p_count[*next_iter];
      }
    }
    return result;
  }
};
