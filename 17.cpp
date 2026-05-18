#include <span>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    dfs(digits, result, {});
    return result;
  }

private:
  void dfs(span<char> digits, vector<string> &result, string &&path) {
    if (digits.empty()) {
      result.push_back(path);
      return;
    }

    auto curr_str = hash_table_.find(digits.front())->second;
    for (const auto &ch : curr_str) {
      path.push_back(ch);
      dfs(digits.subspan(1), result, std::move(path));
      path.pop_back();
    }
  }

  const unordered_map<char, string> hash_table_{
      {'2', "abc"}, {'3', "def"},  {'4', "hgi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
};