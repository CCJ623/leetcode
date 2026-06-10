#include <queue>
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
  // bool isSymmetric(TreeNode *root) {
  //   if (!root) {
  //     return false;
  //   }
  //   return helper(root->left, root->right);
  // }

  bool isSymmetric(TreeNode *root) {
    if (!root) {
      return false;
    }

    std::queue<TreeNode *> q;
    q.push(root->left);
    q.push(root->right);
    while (!q.empty()) {
      auto first = q.front();
      q.pop();
      auto second = q.front();
      q.pop();

      if (!first && !second) {
        continue;
      }
      if (first && second) {
        if (first->val != second->val) {
          return false;
        }
        q.push(first->left);
        q.push(second->right);
        q.push(first->right);
        q.push(second->left);
        continue;
      }
      return false;
    }

    return true;
  }

private:
  auto helper(TreeNode *left, TreeNode *right) -> bool {
    if (!left && !right) {
      return true;
    }
    if (left && right) {
      return left->val == right->val && helper(left->left, right->right) &&
             helper(left->right, right->left);
    }
    return false;
  }
};