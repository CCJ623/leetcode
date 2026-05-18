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
  vector<int> inorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    vector<int> result;
    stack<TreeNode *> s;

    while (!s.empty() || root != nullptr) {
      if (root == nullptr) {
        root = s.top();
        s.pop();
        result.push_back(root->val);
        root = root->right;
      } else {
        s.push(root);
        root = root->left;
      }
    }

    return result;
  }
};