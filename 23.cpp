#include <cstddef>
#include <queue>
#include <vector>

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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode head;
    auto tail = &head;
    auto comparator = [](const ListNode *lhs, const ListNode *rhs) {
      return lhs->val > rhs->val;
    };
    priority_queue<ListNode *, vector<ListNode *>, decltype(comparator)> pq;
    for (const auto &node : lists) {
      if (node) {
        pq.push(node);
      }
    }

    while (!pq.empty()) {
      auto node = std::move(pq.top());
      pq.pop();

      if (node->next) {
        pq.push(node->next);
      }
      tail->next = node;
      tail = tail->next;
    }

    return head.next;
  }
};