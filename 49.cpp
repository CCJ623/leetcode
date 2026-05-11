#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> hash_table;
    for (auto &str : strs) {
      auto sorted_str = str;
      sort(sorted_str.begin(), sorted_str.end());
      hash_table[sorted_str].push_back(str);
    }
    vector<vector<string>> result;
    for (auto &[sorted, strs] : hash_table) {
      result.push_back(std::move(strs));
    }
    return result;
  }
};