#include <array>
#include <string>

using namespace std;

class Trie {
public:
  Trie() {}

  void insert(string word) {
    auto node = &head_;
    for (const auto &ch : word) {
      auto next_node = node->getNext(ch);
      if (next_node == nullptr) {
        node->setNext(ch, new Node(ch));
      }

      node = node->getNext(ch);
    }

    node->setEnd(true);
  }

  bool search(string word) {
    auto node = &head_;
    for (const auto &ch : word) {
      auto next_node = node->getNext(ch);
      if (next_node == nullptr) {
        return false;
      }

      node = node->getNext(ch);
    }

    return node->isEnd();
  }

  bool startsWith(string prefix) {
    auto node = &head_;
    for (const auto &ch : prefix) {
      auto next_node = node->getNext(ch);
      if (next_node == nullptr) {
        return false;
      }

      node = node->getNext(ch);
    }

    return true;
  }

private:
  class Node {
  public:
    Node(char ch, bool is_end) : character_(ch), is_end_(is_end) {
      next_nodes_.fill(nullptr);
    }
    explicit Node(char ch) : Node(ch, false) {}
    Node() : Node(0) {}

    auto get() const -> char { return character_; }
    void set(char ch) { character_ = ch; }
    auto getNext(char ch) -> Node * { return next_nodes_[ch]; }
    void setNext(char ch, Node *next_node) { next_nodes_[ch] = next_node; }
    auto isEnd() const -> bool { return is_end_; }
    void setEnd(bool is_end) { is_end_ = is_end; }

  private:
    char character_{0};
    bool is_end_{false};
    array<Node *, 128> next_nodes_;
  };

  Node head_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */