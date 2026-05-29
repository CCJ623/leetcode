#include <cstddef>
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
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      result.push_back(q.front()->val);
      auto queue_size = q.size();
      for (size_t i = 0; i < queue_size; ++i) {
        auto node = q.front();
        q.pop();
        if (node->right != nullptr) {
          q.push(node->right);
        }

        if (node->left != nullptr) {
          q.push(node->left);
        }
      }
    }

    return result;
  }
};