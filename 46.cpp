#include <span>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
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

    for (size_t i = 0; i < nums.size(); ++i) {
      swap(nums.front(), nums[i]);
      path.push_back(nums.front());
      dfs(nums.subspan(1), result, std::move(path));
      path.pop_back();
      swap(nums.front(), nums[i]);
    }
  }
};