
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }

    for (auto slow = head, fast = slow->next;;
         slow = slow->next, fast = fast->next->next) {
      if (fast->next == nullptr || fast->next->next == nullptr) {
        return false;
      }
      if (fast == slow) {
        return true;
      }
    }
  }
};