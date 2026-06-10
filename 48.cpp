#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    for (size_t level = 0; level < matrix.size() / 2; ++level) {
      for (size_t i = level; i < matrix.size() - level - 1; ++i) {
        swap(matrix[level][i], matrix[i][matrix.size() - level - 1]);
        swap(matrix[level][i],
             matrix[matrix.size() - level - 1][matrix.size() - i - 1]);
        swap(matrix[level][i], matrix[matrix.size() - i - 1][level]);
      }
    }
  }
};
