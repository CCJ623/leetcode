
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

    auto slow = head;
    auto fast = head->next;
    while (slow != fast) {
      if (fast->next == nullptr || fast->next->next == nullptr) {
        return false;
      }

      slow = slow->next;
      fast = fast->next->next;
    }

    return true;
  }
};