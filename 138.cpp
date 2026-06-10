
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head) {
      return nullptr;
    }

    for (auto node = head;;) {
      if (!node) {
        break;
      }

      auto replicate_node = new Node(node->val);
      replicate_node->next = node->next;
      node->next = replicate_node;

      node = replicate_node->next;
    }

    for (auto node = head;;) {
      if (!node) {
        break;
      }

      auto replicate_node = node->next;
      if (node->random) {
        replicate_node->random = node->random->next;
      } else {
        replicate_node->random = nullptr;
      }

      node = replicate_node->next;
    }

    Node dummy_head(0);
    auto previous = &dummy_head;
    for (auto node = head;;) {
      if (!node) {
        break;
      }

      auto replicate_node = node->next;
      previous->next = replicate_node;
      node->next = replicate_node->next;

      previous = previous->next;
      node = node->next;
    }

    return dummy_head.next;
  }
};