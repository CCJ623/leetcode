#include <span>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    dfs(nums, result, {});
    return result;
  }

private:
  void dfs(span<int> nums, vector<vector<int>> &result, vector<int> &&path) {
    if (nums.empty()) {
      result.push_back(path);
      return;
    }

    // select
    path.push_back(nums.front());
    dfs(nums.subspan(1), result, std::move(path));
    path.pop_back();

    // don't select
    dfs(nums.subspan(1), result, std::move(path));
  }
};