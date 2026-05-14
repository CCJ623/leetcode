
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr ||
        head->next->next == nullptr) {
      return nullptr;
    }

    auto slow = head->next, fast = head->next->next;
    // first meet
    for (; slow != fast; slow = slow->next, fast = fast->next->next) {
      if (fast->next == nullptr || fast->next->next == nullptr) {
        return nullptr;
      }
    }
    // second meet
    fast = head;
    for (; slow != fast; slow = slow->next, fast = fast->next) {
    }
    return fast;
  }
};