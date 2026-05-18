#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    stack<char> s;
    vector<string> result;
    string path;
    dfs(s, result, path, n);
    return result;
  }

private:
  void dfs(stack<char> &s, vector<string> &result, string &path, int n) {
    if (n == 0 && s.empty()) {
      result.push_back(path);
      return;
    }

    // add left
    if (n != 0) {
      path.push_back('(');
      s.push('(');

      dfs(s, result, path, n - 1);

      s.pop();
      path.pop_back();
    }

    // add right
    if (!s.empty()) {
      path.push_back(')');
      s.pop();

      dfs(s, result, path, n);

      s.push('(');
      path.pop_back();
    }
  }
};