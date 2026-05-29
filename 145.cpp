#include <cstddef>
#include <stack>
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
  vector<int> postorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    vector<int> result;
    stack<TreeNode *> s;
    TreeNode *previous = nullptr;
    while (!s.empty() || root != nullptr) {
      while (root != nullptr) {
        s.push(root);
        root = root->left;
      }

      root = s.top();
      if (previous != root->right && root->right != nullptr) {
        root = root->right;
      } else {
        result.push_back(root->val);
        previous = root;
        s.pop();
        root = nullptr;
      }
    }

    return result;
  }
};