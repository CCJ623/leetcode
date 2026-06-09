
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy_head;
    dummy_head.next = head;
    auto previous = &dummy_head;
    auto first = head;
    auto second = head;
    for (int i = 0; i < n; ++i) {
      if (!second) {
        return head;
      }
      second = second->next;
    }

    for (; second;
         previous = first, first = first->next, second = second->next) {
    }

    previous->next = first->next;
    return dummy_head.next;
  }
};