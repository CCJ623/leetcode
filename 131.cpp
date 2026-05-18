// #include <print>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> partition(string s) {
    if (s.empty()) {
      return {};
    }
    vector<vector<string>> result;
    vector<string_view> path;

    dfs(result, path, s, 0, 1);
    return result;
  }

private:
  auto isPalindrome(string_view str) -> bool {
    if (str.empty()) {
      return true;
    }

    for (size_t left = 0, right = str.size() - 1; left < right;
         ++left, --right) {
      if (str[left] != str[right]) {
        return false;
      }
    }

    return true;
  }

  void dfs(vector<vector<string>> &result, vector<string_view> &path,
           string_view str, size_t begin, size_t current) {
    if (begin >= str.size()) {
      vector<string> temp;
      for (const auto &str : path) {
        temp.emplace_back(str.begin(), str.end());
      }
      result.push_back(std::move(temp));
      return;
    }

    if (current > str.size()) {
      return;
    }

    // println("begin:{} current:{} path:{}", begin, current, path);

    if (auto cut = str.substr(begin, current - begin); isPalindrome(cut)) {
      path.push_back(cut);

      dfs(result, path, str, current, current + 1);

      path.pop_back();
    }

    dfs(result, path, str, begin, current + 1);
  }
};

int main() {
  string s = "aab";
  Solution{}.partition(s);
}
