#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    if (text1.empty() || text2.empty()) {
      return 0;
    }

    vector<vector<size_t>> dp(text1.size() + 1,
                              vector<size_t>(text2.size() + 1, 0));
    for (size_t i = 1; i < dp.size(); ++i) {
      for (size_t j = 1; j < dp[i].size(); ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }

    return dp.back().back();
  }
};