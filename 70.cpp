class Solution {
public:
  int climbStairs(int n) {
    int one = 1;
    int two = 0;

    for (int i = 0; i < n; ++i) {
      auto new_count = one + two;
      two = one;
      one = new_count;
    }
    return one;
  }
};