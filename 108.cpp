#include <span>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) { return build(nums); }

private:
  auto build(span<const int> nums) -> TreeNode * {
    if (nums.empty()) {
      return nullptr;
    }
    if (nums.size() == 1) {
      return new TreeNode(nums.front(), nullptr, nullptr);
    }

    auto mid_index = nums.size() / 2;
    return new TreeNode(nums[mid_index], build(nums.subspan(0, mid_index)),
                        build(nums.subspan(mid_index + 1)));
  }
};