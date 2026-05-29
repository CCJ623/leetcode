
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto first = headA, second = headB;
    while (first != second) {
      if (first->next == nullptr && second->next == nullptr) {
        return nullptr;
      }

      if (first->next == nullptr) {
        first = headB;
      } else {
        first = first->next;
      }

      if (second->next == nullptr) {
        second = headA;
      } else {
        second = second->next;
      }
    }

    return first;
  }
};