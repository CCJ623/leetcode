#include <algorithm>

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
  int diameterOfBinaryTree(TreeNode *root) {
    maxDepth(root);
    return max_path_length;
  }

private:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    auto left_max = maxDepth(root->left);
    auto right_max = maxDepth(root->right);
    max_path_length = max(max_path_length, left_max + right_max);
    return max(left_max, right_max) + 1;
  }

  int max_path_length = 0;
};