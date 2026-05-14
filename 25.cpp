
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  auto Reverse(ListNode *head, ListNode *tail) -> ListNode * {
    auto first = head, second = head->next;
    for (; second != tail;) {
      auto temp = second->next;
      second->next = first;

      first = second;
      second = temp;
    }

    return first;
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode dummy_head{0, head};
    auto previous = &dummy_head;

    while (true) {
      // find tail
      auto tail = previous->next;
      for (int i = 0; i < k; ++i) {
        if (tail == nullptr) {
          return dummy_head.next;
        }
        tail = tail->next;
      }

      auto old_head = previous->next;
      previous->next = Reverse(previous->next, tail);
      old_head->next = tail;
      previous = old_head;
    }
  }
};