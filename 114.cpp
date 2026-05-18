#include <cstddef>
#include <vector>
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
  void dfs(TreeNode *root, std::vector<TreeNode *> &nodes) {
    if (root == nullptr) {
      return;
    }

    nodes.push_back(root);
    dfs(root->left, nodes);
    dfs(root->right, nodes);
  }

public:
  void flatten(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    std::vector<TreeNode *> nodes;
    dfs(root, nodes);
    for (auto first = nodes.begin(), second = first + 1; second < nodes.end();
         ++first, ++second) {
      (*first)->left = nullptr;
      (*first)->right = (*second);
    }
    nodes.back()->right = nullptr;
  }
};