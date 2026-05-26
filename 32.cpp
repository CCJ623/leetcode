#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> stk;
    stk.push(-1);

    int result = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      char ch = s[i];
      if (ch == '(') {
        stk.push(i);
      } else {
        stk.pop();
        if (stk.empty()) {
          stk.push(i);
        } else {
          result = max(result, static_cast<int>(i - stk.top()));
        }
      }
    }

    return result;
  }
};