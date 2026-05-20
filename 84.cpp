#include <limits>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    auto result = numeric_limits<int>::min();
    stack<size_t> stk;
    for (size_t i = 0; i < heights.size(); ++i) {
      while (!stk.empty() && heights[i] < heights[stk.top()]) {
        auto previous_index = stk.top();
        auto height = heights[previous_index];
        stk.pop();

        previous_index = (stk.empty() ? -1 : stk.top());
        result =
            max(result, height * static_cast<int>((i - previous_index - 1)));
      }
      stk.push(i);
    }

    for (; !stk.empty();) {
      auto previous_index = stk.top();
      auto height = heights[previous_index];
      stk.pop();

      previous_index = (stk.empty() ? -1 : stk.top());
      result =
          max(result,
              height * static_cast<int>((heights.size() - previous_index - 1)));
    }

    return result;
  }
};