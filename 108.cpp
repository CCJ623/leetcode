#include <cstddef>
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
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return build(nums, 0, nums.size());
  }

private:
  auto build(const vector<int> &nums, size_t begin, size_t end) -> TreeNode * {
    if (begin == end) {
      return nullptr;
    }

    auto mid_index = begin + (end - begin) / 2;
    return new TreeNode(nums[mid_index], build(nums, begin, mid_index),
                        build(nums, mid_index + 1, end));
  }
};