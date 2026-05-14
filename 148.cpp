
#include <cstddef>
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
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    auto mid = getMid(head);
    auto left = head;
    auto right = mid->next;
    mid->next = nullptr;
    return merge(sortList(left), sortList(right));
  }

private:
  auto getMid(ListNode *head) -> ListNode * {
    auto slow = head;
    auto fast = slow->next;

    for (; fast != nullptr && fast->next != nullptr;) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

  auto merge(ListNode *first, ListNode *second) -> ListNode * {
    ListNode dummy_head{0, nullptr};
    auto tail = &dummy_head;
    for (;;) {
      if (first == nullptr && second == nullptr) {
        return dummy_head.next;
      }

      if (first != nullptr && second != nullptr) {
        if (first->val < second->val) {
          tail->next = first;
          first = first->next;
        } else {
          tail->next = second;
          second = second->next;
        }
        tail = tail->next;
        continue;
      }

      if (first != nullptr) {
        tail->next = first;
        return dummy_head.next;
      }

      tail->next = second;
      return dummy_head.next;
    }
  }
};