
#include <limits>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr) {
      return list2;
    }
    if (list2 == nullptr) {
      return list1;
    }

    ListNode head{std::numeric_limits<int>::min()};
    auto tail = &head;
    auto first = list1;
    auto second = list2;

    for (; first != nullptr && second != nullptr; tail = tail->next) {
      if (first->val < second->val) {
        tail->next = first;
        first = first->next;
      } else {
        tail->next = second;
        second = second->next;
      }
    }

    if (first != nullptr) {
      tail->next = first;
    } else if (second != nullptr) {
      tail->next = second;
    }

    return head.next;
  }
};