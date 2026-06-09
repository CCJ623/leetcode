
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
    ListNode head;
    auto tail = &head;
    int carry = false;
    while (l1 || l2 || carry != 0) {
      auto new_node = new ListNode();
      if (l1 && l2) {
        auto sum = l1->val + l2->val + carry;
        new_node->val = sum % 10;
        carry = sum / 10;

        l1 = l1->next;
        l2 = l2->next;
      } else if (l1) {
        auto sum = l1->val + carry;
        new_node->val = sum % 10;
        carry = sum / 10;

        l1 = l1->next;
      } else if (l2) {
        auto sum = l2->val + carry;
        new_node->val = sum % 10;
        carry = sum / 10;

        l2 = l2->next;
      } else {
        auto sum = carry;
        new_node->val = sum % 10;
        carry = sum / 10;
      }

      tail->next = new_node;
      tail = new_node;
    }

    return head.next;
  }
};