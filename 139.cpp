#include <string>
#include <string_view>
#include <vector>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    vector<bool> dp;
    dp.reserve(s.size() + 1);
    dp.push_back(true);

    for (size_t i = 1; i <= s.size(); ++i) {
      auto is_success = false;
      for (const auto &word : wordDict) {
        if (word.size() > i || dp[i - word.size()] == false) {
          continue;
        }
        if (string_view{s.data() + (i - word.size()), word.size()} == word) {
          is_success = true;
          break;
        }
      }
      dp.push_back(is_success);
    }

    return dp.back();
  }
};