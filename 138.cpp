
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
    if (head == nullptr) {
      return nullptr;
    }

    // replicate
    for (auto curr_node = head; curr_node != nullptr;) {
      auto new_node = new Node(curr_node->val);
      new_node->next = curr_node->next;
      curr_node->next = new_node;
      curr_node = new_node->next;
    }

    // set random
    for (auto old_node = head; old_node != nullptr;) {
      auto new_node = old_node->next;
      if (old_node->random != nullptr) {
        new_node->random = old_node->random->next;
      }

      old_node = new_node->next;
    }

    Node *result = head->next;
    // split
    for (auto old_node = head; old_node != nullptr;) {
      auto new_node = old_node->next;
      old_node->next = new_node->next;
      if (new_node->next != nullptr) {
        new_node->next = new_node->next->next;
      }

      old_node = old_node->next;
      new_node = new_node->next;
    }

    return result;
  }
};