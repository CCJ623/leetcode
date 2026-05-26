#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 0) {
      return {};
    }

    vector<vector<int>> result;
    result.reserve(numRows);
    result.push_back({1});
    for (int i = 1; i < numRows; ++i) {
      vector<int> new_row;
      new_row.reserve(i * 2 + 1);
      new_row.push_back(result[i - 1].front());
      const auto &previous_row = result[i - 1];
      for (size_t left = 0, right = 1; right < previous_row.size();
           ++left, ++right) {
        new_row.push_back(previous_row[left] + previous_row[right]);
      }
      new_row.push_back(previous_row.back());
      result.push_back(std::move(new_row));
    }

    return result;
  }
};