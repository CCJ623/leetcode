#include <stack>

using namespace std;

class MinStack {
public:
  MinStack() {}

  void push(int val) {
    stack_.push(val);
    if (min_stack_.empty()) {
      min_stack_.push(val);
    } else {
      min_stack_.push(min(min_stack_.top(), val));
    }
  }

  void pop() {
    stack_.pop();
    min_stack_.pop();
  }

  int top() { return stack_.top(); }

  int getMin() { return min_stack_.top(); }

private:
  stack<int> stack_;
  stack<int> min_stack_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */