#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> hash_table;
    for (const auto &str : strs) {
      auto sorted_str = str;
      ranges::sort(sorted_str);
      hash_table[sorted_str].emplace_back(str);
    }

    vector<vector<string>> result;
    result.reserve(strs.size());
    for (auto &[key, value] : hash_table) {
      result.emplace_back(std::move(value));
    }

    return result;
  }
};