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
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    return helper(root->left, root->right);
  }

private:
  auto helper(TreeNode *left, TreeNode *right) -> bool {
    if (left == nullptr && right == nullptr) {
      return true;
    }
    if (left == nullptr || right == nullptr || left->val != right->val) {
      return false;
    }
    return helper(left->left, right->right) && helper(left->right, right->left);
  }
};