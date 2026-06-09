#include <cstddef>
#include <functional>
#include <memory>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
  LRUCache(int capacity) : capacity_(capacity) {
    head_.next_ = &tail_;
    tail_.previous_ = &head_;
  }

  int get(int key) {
    auto iter = hash_table_.find(key);
    if (iter == hash_table_.end()) {
      return -1;
    }

    auto &node = *iter->second;
    MoveToHead(node);
    return node.value_;
  }

  void put(int key, int value) {
    auto iter = hash_table_.find(key);
    if (iter != hash_table_.end()) {
      // exist
      auto &node = *iter->second;
      node.value_ = value;
      MoveToHead(node);
      return;
    }

    // not exist
    while (isFull()) {
      evict();
    }

    auto node_ptr = make_unique<ListNode>();
    auto &node = *node_ptr;
    node.key_ = key;
    node.value_ = value;
    hash_table_.emplace(node.key_, std::move(node_ptr));
    addToHead(node);
  }

private:
  struct ListNode {
    int key_ = -1;
    int value_ = -1;
    ListNode *previous_ = nullptr;
    ListNode *next_ = nullptr;
  };

  void remove(ListNode &node) {
    node.previous_->next_ = node.next_;
    node.next_->previous_ = node.previous_;
  }

  void addToHead(ListNode &node) {
    node.previous_ = &head_;
    node.next_ = head_.next_;
    head_.next_->previous_ = &node;
    head_.next_ = &node;
  }

  auto isFull() -> bool {
    return static_cast<int>(hash_table_.size()) >= capacity_;
  }

  void evict() {
    auto node = *tail_.previous_;
    remove(node);
    hash_table_.erase(node.key_);
  }

  void MoveToHead(ListNode &node) {
    remove(node);
    addToHead(node);
  }

  ListNode head_;
  ListNode tail_;
  unordered_map<int, unique_ptr<ListNode>> hash_table_;
  int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */