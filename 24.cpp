
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

    ListNode my_head{0, head};
    auto previous = &my_head;
    while (previous->next != nullptr && previous->next->next != nullptr) {
      auto first = previous->next;
      auto second = first->next;

      first->next = second->next;
      second->next = first;
      previous->next = second;
      previous = first;
    }

    return my_head.next;
  }
};