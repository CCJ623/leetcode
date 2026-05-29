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
    vector<int> result;
    stack<TreeNode *> stk;
    while (!stk.empty() || root != nullptr) {
      while (root != nullptr) {
        stk.push(root);
        root = root->left;
      }
      root = stk.top();
      stk.pop();
      result.push_back(root->val);
      root = root->right;
    }

    return result;
  }
};