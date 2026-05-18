
#include <algorithm>
#include <functional>
#include <limits>
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
  bool helper(TreeNode *root, const std::pair<long, long> &range) {
    if (root == nullptr) {
      return true;
    }
    auto root_value = static_cast<long>(root->val);
    return (range.first < root_value && root_value < range.second) &&
           helper(root->left,
                  {range.first, std::min(range.second, root_value)}) &&
           helper(root->right,
                  {std::max(range.first, root_value), range.second});
  }

public:
  bool isValidBST(TreeNode *root) {
    if (root == nullptr) {
      return false;
    }
    return helper(root, {std::numeric_limits<long>::min(),
                         std::numeric_limits<long>::max()});
  }
};