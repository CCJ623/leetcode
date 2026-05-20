#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> stk;
    for (auto ch : s) {
      if (hash_table_.contains(ch)) {
        // left
        stk.push(ch);
      } else {
        // right
        if (!stk.empty() && isMatch(stk.top(), ch)) {
          stk.pop();
        } else {
          return false;
        }
      }
    }

    return stk.empty();
  }

private:
  auto isMatch(char left, char right) -> bool {
    return hash_table_.at(left) == right;
  }

  const unordered_map<char, char> hash_table_ = {
      {'(', ')'}, {'[', ']'}, {'{', '}'}};
};