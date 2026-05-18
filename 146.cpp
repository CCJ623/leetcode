#include <cstddef>
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
    if (!hash_table_.contains(key)) {
      return -1;
    }

    auto &node = *hash_table_[key];
    moveToFront(node);
    return node.value_;
  }

  void put(int key, int value) {
    auto iter = hash_table_.find(key);
    if (iter == hash_table_.end()) {
      auto new_node = make_unique<ListNode>(key, value);
      while (static_cast<int>(hash_table_.size()) >= capacity_) {
        evict();
      }
      addToHead(*new_node);
      hash_table_[key] = std::move(new_node);
    } else {
      auto &node = *iter->second;
      node.value_ = value;
      moveToFront(node);
    }
  }

private:
  struct ListNode {
    ListNode() = default;
    ListNode(int key, int value) : key_(key), value_(value) {}

    int key_ = 0;
    int value_ = 0;
    ListNode *previous_ = nullptr;
    ListNode *next_ = nullptr;
  };

  void remove(ListNode &node) {
    node.previous_->next_ = node.next_;
    node.next_->previous_ = node.previous_;
  }

  void addToHead(ListNode &node) {
    node.next_ = head_.next_;
    node.previous_ = &head_;
    head_.next_->previous_ = &node;
    head_.next_ = &node;
  }

  void moveToFront(ListNode &node) {
    remove(node);
    addToHead(node);
  }

  void evict() {
    auto &last_node = *tail_.previous_;
    remove(last_node);
    hash_table_.erase(last_node.key_);
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