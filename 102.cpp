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
    if (root == nullptr) {
      return {};
    }

    vector<vector<int>> result;
    queue<TreeNode *> current_queue;
    queue<TreeNode *> next_queue;
    next_queue.push(root);
    while (!next_queue.empty()) {
      swap(current_queue, next_queue);
      vector<int> level_result;
      while (!current_queue.empty()) {
        auto node = current_queue.front();
        current_queue.pop();
        level_result.push_back(node->val);
        if (node->left != nullptr) {
          next_queue.push(node->left);
        }
        if (node->right != nullptr) {
          next_queue.push(node->right);
        }
      }

      result.push_back(std::move(level_result));
    }
    return result;
  }
};