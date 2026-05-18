#include <algorithm>
#include <ranges>
#include <span>
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
  TreeNode *helper(span<const int> preorder, span<const int> inorder) {
    if (preorder.empty() || inorder.empty()) {
      return nullptr;
    }

    auto node = new TreeNode(preorder.front());
    auto separator = ranges::find(inorder, node->val) - inorder.begin();
    auto left_span = inorder | ranges::views::take(separator);
    auto right_span = inorder | ranges::views::drop(separator + 1);
    node->left = helper(preorder.subspan(1, left_span.size()), left_span);
    node->right = helper(preorder.subspan(1 + left_span.size()), right_span);

    return node;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return helper(preorder, inorder);
  }
};