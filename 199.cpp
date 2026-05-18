#include <queue>

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
  vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    vector<int> result;
    queue<TreeNode *> current_level{};
    queue<TreeNode *> next_level{};
    next_level.push(root);

    while (!next_level.empty()) {
      swap(current_level, next_level);
      result.push_back(current_level.front()->val);
      while (!current_level.empty()) {
        auto node = current_level.front();
        current_level.pop();
        if (node->right != nullptr) {
          next_level.push(node->right);
        }
        if (node->left != nullptr) {
          next_level.push(node->left);
        }
      }
    }

    return result;
  }
};