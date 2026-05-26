#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    if (s.empty()) {
      return {};
    }

    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    size_t result_start = 0;
    size_t result_end = 0;
    for (size_t i = 0; i < dp.size(); ++i) {
      dp[i][i] = true;
    }
    for (size_t i = 0; i < dp.size() - 1; ++i) {
      dp[i][i + 1] = (s[i] == s[i + 1]);
      if (dp[i][i + 1]) {
        result_start = i;
        result_end = i + 1;
      }
    }

    for (size_t length = 3; length <= s.size(); ++length) {
      for (size_t start = 0; start < s.size(); ++start) {
        auto end = start + length - 1;
        if (end >= s.size()) {
          break;
        }

        dp[start][end] = (dp[start + 1][end - 1] && s[start] == s[end]);
        if (dp[start][end] && (end - start) > (result_end - result_start)) {
          result_start = start;
          result_end = end;
        }
      }
    }

    return s.substr(result_start, result_end - result_start + 1);
  }
};