
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next || !head->next->next) {
      return nullptr;
    }

    auto slow = head->next;
    auto fast = head->next->next;
    while (slow != fast) {
      if (!fast->next || !fast->next->next) {
        return nullptr;
      }

      slow = slow->next;
      fast = fast->next->next;
    }

    fast = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }
};