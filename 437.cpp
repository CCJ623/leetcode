#include <unordered_map>

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
  int dfs(TreeNode *root, int target_sum, long long sum_to_root,
          unordered_map<long long, size_t> &hash_table) {
    if (root == nullptr) {
      return 0;
    }

    sum_to_root += root->val;
    int count_ = 0;
    count_ += hash_table[sum_to_root - target_sum];
    ++hash_table[sum_to_root];

    count_ += dfs(root->left, target_sum, sum_to_root, hash_table);
    count_ += dfs(root->right, target_sum, sum_to_root, hash_table);

    --hash_table[sum_to_root];
    return count_;
  }

public:
  int pathSum(TreeNode *root, int targetSum) {
    unordered_map<long long, size_t> hash_table;
    hash_table.emplace(0, 1);

    return dfs(root, targetSum, 0, hash_table);
  }
};