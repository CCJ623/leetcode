#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string s) {
    if (s.empty()) {
      return {};
    }

    unordered_map<char, size_t> hash_table;
    vector<int> result;

    for (size_t i = 0; i < s.size(); ++i) {
      auto ch = s[i];
      hash_table[ch] = max(hash_table[ch], i);
    }

    size_t start = 0;
    size_t end = 1;
    for (size_t i = 0; i < s.size(); ++i) {
      if (i == end) {
        result.emplace_back(end - start);
        start = end;
      }
      end = max(end, hash_table[s[i]] + 1);
      if (end >= s.size()) {
        result.emplace_back(end - start);
        return result;
      }
    }

    result.emplace_back(end - start);
    return result;
  }
};