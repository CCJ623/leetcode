
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }

    int carry = 0;
    auto first = l1;
    auto second = l2;

    while (true) {
      auto num = first->val + second->val + carry;
      carry = num / 10;
      first->val = num % 10;

      if (first->next == nullptr || second->next == nullptr) {
        break;
      } else {
        first = first->next;
        second = second->next;
      }
    }

    if (first->next != nullptr) {
      first = first->next;
    } else if (second->next != nullptr) {
      first->next = second->next;
      first = first->next;
    } else if (carry != 0) {
      first->next = new ListNode(carry);
      return l1;
    } else {
      return l1;
    }

    while (true) {
      auto num = first->val + carry;
      carry = num / 10;
      first->val = num % 10;

      if (first->next == nullptr) {
        break;
      } else {
        first = first->next;
      }
    }

    if (carry != 0) {
      first->next = new ListNode(carry);
    }

    return l1;
  }
};