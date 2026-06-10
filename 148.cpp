
#include <cstddef>
#include <functional>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    auto slow = head;
    auto fast = head;
    for (; fast->next && fast->next->next;
         slow = slow->next, fast = fast->next->next)
      ;

    auto left = head;
    auto right = slow->next;
    slow->next = nullptr;

    left = sortList(left);
    right = sortList(right);

    ListNode dummy_head;
    auto previous = &dummy_head;
    for (; left || right;) {
      reference_wrapper<ListNode *> target = left;
      if (left && right) {
        target = (left->val < right->val ? left : right);
      } else if (left) {
        target = left;
      } else {
        target = right;
      }

      previous->next = target;
      previous = previous->next;
      target.get() = target.get()->next;
    }

    return dummy_head.next;
  }
};