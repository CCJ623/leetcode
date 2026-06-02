
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head) {
      return nullptr;
    }

    ListNode dummy_head;
    auto previous = &dummy_head;
    while (true) {
      auto tail = head;
      for (int i = 0; i < k; ++i) {
        if (!tail) {
          return dummy_head.next;
        }

        tail = tail->next;
      }

      previous->next = reverse(head, tail);
      previous = head;
      head->next = tail;
      head = tail;
    }

    return dummy_head.next;
  }

private:
  ListNode *reverse(ListNode *head, ListNode *tail) {
    ListNode *first = nullptr;
    auto second = head;
    while (second != tail) {
      auto temp = second->next;
      second->next = first;
      first = second;
      second = temp;
    }

    return first;
  }
};