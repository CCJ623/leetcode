#include <queue>
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> level;
      auto count = q.size();
      for (size_t i = 0; i < count; ++i) {
        auto node = q.front();
        q.pop();
        if (!node) {
          continue;
        }
        level.push_back(node->val);
        q.push(node->left);
        q.push(node->right);
      }

      if (!level.empty()) {
        result.push_back(std::move(level));
      }
    }

    return result;
  }
};