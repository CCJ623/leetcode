#include <span>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(candidates, result, path, 0, target);
    return result;
  }

private:
  void dfs(span<int> candidate, vector<vector<int>> &result, vector<int> &path,
           int path_sum, const int &target) {
    if (path_sum > target) {
      return;
    } else if (path_sum == target) {
      result.push_back(path);
      return;
    }

    for (size_t i = 0; i < candidate.size(); ++i) {
      path.push_back(candidate[i]);
      path_sum += candidate[i];

      dfs(candidate.subspan(i), result, path, path_sum, target);

      path.pop_back();
      path_sum -= candidate[i];
    }
  }
};