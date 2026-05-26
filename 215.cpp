#include <functional>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    if (nums.size() < static_cast<size_t>(k)) {
      return -1;
    }

    Heap<decay_t<decltype(nums)>::value_type, greater<>> heap;
    for (const auto &num : nums) {
      if (heap.size() < static_cast<size_t>(k)) {
        heap.push(num);
        continue;
      }

      if (num > heap.top()) {
        heap.pop();
        heap.push(num);
      }
    }

    return heap.top();
  }

private:
  template <typename T, typename Comparator = less<T>> class Heap {
  public:
    Heap() {}

    auto size() const -> size_t { return container_.size(); }
    void push(const T &element) {
      container_.push_back(element);
      siftUp();
    }
    void pop() {
      swap(container_.front(), container_.back());
      container_.pop_back();
      siftDown();
    }
    auto top() const -> const T & { return container_.front(); }

  private:
    void siftUp() {
      for (auto index = container_.size() - 1; index > 0;
           index = getUpstream(index)) {
        auto &element = container_[index];
        auto &upstream_element = container_[getUpstream(index)];
        if (Comparator{}(element, upstream_element)) {
          return;
        }
        swap(element, upstream_element);
      }
    }

    void siftDown() {
      for (size_t index = 0;
           index < container_.size() && getLeft(index) < container_.size();) {
        auto &element = container_[index];
        auto left_index = getLeft(index);
        auto right_index = getRight(index);
        auto target_index = left_index;

        if (right_index < container_.size() &&
            Comparator{}(container_[left_index], container_[right_index])) {
          target_index = right_index;
        }

        auto &target_element = container_[target_index];
        if (Comparator{}(target_element, element)) {
          return;
        }

        swap(element, target_element);
        index = target_index;
      }
    }

    auto getLeft(size_t index) const -> size_t { return 2 * index + 1; }

    auto getRight(size_t index) const -> size_t { return getLeft(index) + 1; }

    auto getUpstream(size_t index) const -> size_t { return (index - 1) / 2; }

    vector<T> container_;
  };
};