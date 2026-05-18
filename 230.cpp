
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
  int kthSmallest(TreeNode *root, int k) {
    if (root == nullptr) {
      return -1;
    }
    dfs(root, k);
    return result_.value_or(-1);
  }

private:
  void dfs(TreeNode *root, const int &k) {
    if (root == nullptr) {
      return;
    }
    dfs(root->left, k);
    ++count_;
    if (static_cast<int>(count_) == k) {
      result_ = root->val;
      return;
    } else if (static_cast<int>(count_) > k) {
      return;
    }
    dfs(root->right, k);
  }

  size_t count_{0};
  std::optional<int> result_;
};