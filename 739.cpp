#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<int> result(temperatures.size(), 0);
    stack<size_t> stk;

    for (size_t i = 0; i < temperatures.size(); ++i) {
      if (stk.empty()) {
        stk.push(i);
        continue;
      }

      while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
        auto previous_index = stk.top();
        stk.pop();

        result[previous_index] = i - previous_index;
      }

      stk.push(i);
    }

    return result;
  }
};