#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    vector<int> v;
    for (auto node = head; node; node = node->next) {
      v.push_back(node->val);
    }

    for (size_t left = 0, right = v.size() - 1; left < right; ++left, --right) {
      if (v[left] != v[right]) {
        return false;
      }
    }

    return true;
  }
};