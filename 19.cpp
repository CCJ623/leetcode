
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
    if (head == nullptr) {
      return nullptr;
    }

    ListNode my_head{0, head};
    auto first = &my_head;
    auto second = first;
    for (int i = 0; i < n + 1; ++i) {
      if (second == nullptr) {
        return nullptr;
      }
      second = second->next;
    }

    for (; second != nullptr; first = first->next, second = second->next) {
    }

    first->next = first->next->next;

    return my_head.next;
  }
};