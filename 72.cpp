#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    vector<vector<size_t>> dp(word1.size() + 1,
                              vector<size_t>(word2.size() + 1, 0));
    for (size_t row = 0; row < dp.size(); ++row) {
      dp[row].front() = row;
    }
    for (size_t col = 0; col < dp.front().size(); ++col) {
      dp.front()[col] = col;
    }

    for (size_t row = 1; row < dp.size(); ++row) {
      for (size_t col = 1; col < dp[row].size(); ++col) {
        if (word1[row - 1] == word2[col - 1]) {
          dp[row][col] = dp[row - 1][col - 1];
        } else {
          dp[row][col] = min({dp[row - 1][col - 1] + 1, dp[row][col - 1] + 1,
                              dp[row - 1][col] + 1});
        }
      }
    }

    return dp.back().back();
  }
};