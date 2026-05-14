#include <functional>
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
    if (lists.empty()) {
      return nullptr;
    }

    auto node_comparator = [](ListNode *lhs, ListNode *rhs) {
      return lhs->val > rhs->val;
    };
    ListNode dummy_head{0, nullptr};
    auto tail = &dummy_head;
    priority_queue<ListNode *, vector<ListNode *>, decltype(node_comparator)>
        pq;
    for (auto &node : lists) {
      if (node != nullptr) {
        pq.push(node);
      }
    }

    while (!pq.empty()) {
      auto node = pq.top();
      pq.pop();
      tail->next = node;
      if (node->next != nullptr) {
        pq.push(node->next);
      }
      tail = tail->next;
    }

    return dummy_head.next;
  }
};