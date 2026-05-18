#include <algorithm>
#include <limits>
#include <optional>

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
  int maxPathSum(TreeNode *root) {
    helper(root);
    return result_;
  }

private:
  std::optional<int> helper(TreeNode *root) {
    if (root == nullptr) {
      return std::nullopt;
    }

    auto left = helper(root->left);
    auto right = helper(root->right);
    int no_cross_max = root->val;
    if (left.has_value()) {
      no_cross_max = std::max(no_cross_max, root->val + *left);
    }
    if (right.has_value()) {
      no_cross_max = std::max(no_cross_max, root->val + *right);
    }

    if (left.has_value() && right.has_value()) {
      result_ = std::max({result_, no_cross_max, *left + root->val + *right});
    } else {
      result_ = std::max(result_, no_cross_max);
    }

    return no_cross_max;
  }

  int result_{std::numeric_limits<int>::min()};
};