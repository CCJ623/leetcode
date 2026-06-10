
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (!head) {
      return nullptr;
    }

    ListNode dummy_head(0, head);
    auto previous = &dummy_head;

    for (auto first = head, second = first->next; second;) {
      auto next_node = second->next;
      second->next = first;
      first->next = next_node;
      previous->next = second;

      if (!next_node) {
        break;
      }
      previous = first;
      first = next_node;
      second = first->next;
    }

    return dummy_head.next;
  }
};