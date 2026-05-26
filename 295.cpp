#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

class MedianFinder {
public:
  MedianFinder() {}

  void addNum(int num) {
    if (max_heap_.size() == min_heap_.size()) {
      max_heap_.push(num);
      min_heap_.push(max_heap_.top());
      max_heap_.pop();
    } else {
      min_heap_.push(num);
      max_heap_.push(min_heap_.top());
      min_heap_.pop();
    }
  }

  double findMedian() {
    if ((max_heap_.size() + min_heap_.size()) % 2 == 0) {
      return static_cast<double>(max_heap_.top() + min_heap_.top()) / 2;
    }

    return min_heap_.top();
  }

private:
  priority_queue<int, vector<int>, less<>> max_heap_;
  priority_queue<int, vector<int>, greater<>> min_heap_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */