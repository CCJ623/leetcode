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
    vector<int> result;
    stack<TreeNode *> stk;
    TreeNode *previous = nullptr;
    while (!stk.empty() || root) {
      while (root) {
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      if (root->right == previous || !root->right) {
        stk.pop();
        result.push_back(root->val);
        previous = root;
        root = nullptr;
      } else {
        root = root->right;
      }
    }

    return result;
  }
};